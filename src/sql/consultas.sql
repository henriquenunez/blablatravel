-- 1
-- Consulta todas os fotos de um passeio junto com as fotos tiradas no passeio pelos turistas
-- Neste caso estamos consultando um passeio ao cristo redentor, entao todos as fotos sï¿½o links para fotos do cristo redentor
(
    SELECT FP.FOTO
    FROM FOTOS_PASSEIO FP
    WHERE FP.GUIA = 'breno@gmail.com' AND FP.DATA=TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS')
)
UNION ALL
(
    SELECT FP.FOTO
    FROM PARTICIPACAO PART
    JOIN FOTOS_PARTICIPACAO FP ON FP.PARTICIPACAO = PART.NRO_PARTICIPACAO
    WHERE PART.GUIA = 'breno@gmail.com' AND PART.DATA=TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS')
);

--2
-- Busca todos os turistas que passaram em uma atração que percente a categoria 'Building'
-- Neste caso vai retornar todos os turista que foram em passeios na 'Eiffel Tower' e 'Christ the Redeemer'
SELECT DISTINCT PARTICIPACAO.TURISTA
FROM ATRACAO_CATEGORIA
JOIN PASSEIO_ATRACAO
 ON PASSEIO_ATRACAO.ATRACAO = ATRACAO_CATEGORIA.ATRACAO
JOIN PARTICIPACAO
 ON PARTICIPACAO.GUIA = PASSEIO_ATRACAO.GUIA AND PARTICIPACAO.DATA = PASSEIO_ATRACAO.DATA
WHERE ATRACAO_CATEGORIA.CATEGORIA = 'Building';

-- 3
--- Quais guias fazem mais passeios que a média dos guias que fizeram passeios?
WITH PASS_N AS
    (
        SELECT PASSEIO.GUIA, COUNT(*) AS C
        FROM PASSEIO
        GROUP BY PASSEIO.GUIA
    )
SELECT PASS_N.guia
FROM PASS_N
WHERE PASS_N.C > (SELECT AVG(PASS_N.C) FROM PASS_N);

-- 4
-- Quais turistas visitaram todas as atrações da categoria “Building”?
SELECT T.USUARIO AS TURISTA FROM TURISTA T
WHERE NOT EXISTS
(
    ( SELECT AC.ATRACAO FROM ATRACAO_CATEGORIA AC WHERE AC.CATEGORIA = 'Building')
    EXCEPT
    (
        SELECT PA.ATRACAO FROM PARTICIPACAO P
        JOIN PASSEIO_ATRACAO PA
        ON PA.GUIA = P.GUIA AND PA.DATA = P.DATA
        WHERE P.TURISTA = T.USUARIO
    )
);


-- 5
-- Busca as últimas N mensagens que o usuário trocou,
-- mas com o limite de uma por conversa. Ordenadas da
-- mais recente para a mais antiga.
WITH MSG AS --Selecionando usuários aos quais houve mensagem
(
     (
         SELECT USUARIO_RECEBE as USUARIO, DATA, MENSAGEM as M
         FROM MENSAGEM
         WHERE USUARIO_ENVIA = 'dikson@gmail.com'
     )
     UNION
     (
         SELECT USUARIO_ENVIA as USUARIO, DATA, MENSAGEM as M
         FROM MENSAGEM
         WHERE USUARIO_RECEBE = 'dikson@gmail.com'
     )
)
SELECT A.USUARIO, A.DATA, A.M
FROM MSG A
INNER JOIN
    (
        SELECT A.USUARIO, MAX(A.DATA) AS MD
        FROM MSG A
        GROUP BY A.USUARIO
    )
    B ON A.USUARIO = B.USUARIO AND A.DATA = B.MD;

-- 5 alternativa
-- Uma solução bem elegante, não é mesmo?
WITH MSG AS --Selecionando usuários aos quais hove mensagem
(
     (
         SELECT USUARIO_RECEBE as USUARIO, DATA, MENSAGEM as M
         FROM MENSAGEM
         WHERE USUARIO_ENVIA = 'dikson@gmail.com'
     )
     UNION
     (
         SELECT USUARIO_ENVIA as USUARIO, DATA, MENSAGEM as M
         FROM MENSAGEM
         WHERE USUARIO_RECEBE = 'dikson@gmail.com'
     )
)
SELECT A.USUARIO, A.DATA, A.M
FROM MSG A
LEFT OUTER JOIN MSG B ON A.USUARIO = B.USUARIO AND A.DATA < B.DATA
WHERE B.USUARIO IS NULL;
-- Usuário é um identificador de grupo, então está comparando entre as tuplas do mesmo grupo.
-- Se b.usuario é nulo, quer dizer que nenhuma tupla de B deu match em A, ou seja, essa tupla de A
-- tem a maior data.


-- 6
-- Calcula quantidade de participações que aconteceram em cada categoria de atração
SELECT CAT.NOME, COUNT(P.NRO_PARTICIPACAO)
FROM CATEGORIA CAT
LEFT JOIN ATRACAO_CATEGORIA AC
    ON AC.CATEGORIA = CAT.NOME
LEFT JOIN PASSEIO_ATRACAO PA
    ON AC.ATRACAO = PA.ATRACAO
LEFT JOIN PARTICIPACAO P
    ON PA.DATA = P.DATA AND PA.GUIA = P.GUIA
GROUP BY CAT.NOME;

-- 7
-- As 5 atrações mais visitadas pelos turistas que criaram pelo menos dois relatos
SELECT PA.ATRACAO, COUNT(*) AS QUANTIDADE FROM (
 SELECT R.USUARIO FROM (
    SELECT RB.USUARIO FROM RELATO_DE_BUG RB
 UNION ALL
    SELECT RV.USUARIO FROM RELATO_DE_VIAGEM RV
 ) R
 GROUP BY R.USUARIO
 HAVING COUNT(*)>=2
) U
JOIN PARTICIPACAO P
 ON P.TURISTA = U.USUARIO
JOIN PASSEIO_ATRACAO PA
 ON PA.GUIA = P.GUIA AND PA.DATA = P.DATA
GROUP BY PA.ATRACAO
ORDER BY QUANTIDADE DESC
LIMIT (5);

-- Consultas adicionais criadas no desenvolvimento

-- Busca todas as pessoas que a pessoa j� conversou por ordem, da mais recente at� a mais antiga
SELECT E.USUARIO FROM (SELECT U.USUARIO, MAX(U.DATA) as DATA FROM (
	(
		SELECT USUARIO_RECEBE as USUARIO, DATA FROM MENSAGEM M
		WHERE USUARIO_ENVIA = 'dikson@gmail.com'
	)
	UNION
	(
		SELECT USUARIO_ENVIA  as USUARIO, DATA FROM MENSAGEM
		WHERE USUARIO_RECEBE = 'dikson@gmail.com'
	)) U
GROUP BY U.USUARIO
ORDER BY DATA DESC) E;

-- Busca as ultimas 10 mensagens entre duas pessoas ordenado pela hora que enviou a mensagem
SELECT *
FROM MENSAGEM
WHERE
	(USUARIO_ENVIA = 'dikson@gmail.com' AND USUARIO_RECEBE = 'hiram@gmail.com')
	OR (USUARIO_ENVIA = 'hiram@gmail.com' AND USUARIO_RECEBE = 'dikson@gmail.com')
ORDER BY DATA DESC
LIMIT(10);

-- Quantidade de relatos que ocorreram em cada atração aceita (TODO nao ta mostrando zero)
SELECT PA.ATRACAO, COUNT(*)
FROM RELATO_DE_VIAGEM RV
JOIN PARTICIPACAO ON
	PARTICIPACAO.NRO_PARTICIPACAO = RV.PARTICIPACAO
JOIN PASSEIO_ATRACAO PA ON
	PA.GUIA = PARTICIPACAO.GUIA AND PA.DATA = PARTICIPACAO.DATA
GROUP BY PA.ATRACAO;
