-- Consulta todas os fotos de um passeio junto com as fotos tiradas no passeio pelos turistas
-- Neste caso estamos consultando um passeio ao cristo redentor, entao todos as fotos são links para fotos do cristo redentor
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

-- Busca todos os passeio que possuem uma atração que pertencem a categoria 'Building'
-- Neste caso vai retornar todos os passeios relacionados com as atrações 'Eiffel Tower' e 'Christ the Redeemer'
SELECT PASSEIO.* 
FROM PASSEIO 
JOIN PASSEIO_ATRACAO
	ON PASSEIO_ATRACAO.GUIA = PASSEIO.GUIA AND PASSEIO_ATRACAO.DATA = PASSEIO.DATA
JOIN ATRACAO
	ON PASSEIO_ATRACAO.ATRACAO = ATRACAO
JOIN ATRACAO_CATEGORIA
	ON ATRACAO_CATEGORIA.CATEGORIA = 'Building' AND ATRACAO_CATEGORIA.ATRACAO = ATRACAO.NOME;
    
    
-- Busca todas as pessoas que a pessoa já conversou por ordem, da mais recente até a mais antiga
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
LIMIT(10)

-- Calcula quantidade de participações que aconteceram em cada tipo de atração (TODO nao ta mostrando zero)
SELECT PA.ATRACAO, COUNT(*) FROM PARTICIPACAO
JOIN PASSEIO_ATRACAO PA 
	ON PA.GUIA = PARTICIPACAO.GUIA AND PA.DATA = PARTICIPACAO.DATA
GROUP BY PA.ATRACAO;

-- Calcula quantidade de participações que aconteceram em cada categoria de atração (TODO nao ta mostrando zero)
SELECT AC.CATEGORIA, COUNT(*) FROM PARTICIPACAO
JOIN PASSEIO_ATRACAO PA 
	ON PA.GUIA = PARTICIPACAO.GUIA AND PA.DATA = PARTICIPACAO.DATA
JOIN ATRACAO_CATEGORIA AC 
	ON AC.ATRACAO = PA.ATRACAO
GROUP BY AC.CATEGORIA;

-- Quantidade de relatos que ocorreram em cada atração aceita (TODO nao ta mostrando zero)
SELECT PA.ATRACAO, COUNT(*) 
FROM RELATO_DE_VIAGEM RV
JOIN PARTICIPACAO ON
	PARTICIPACAO.NRO_PARTICIPACAO = RV.PARTICIPACAO
JOIN PASSEIO_ATRACAO PA ON
	PA.GUIA = PARTICIPACAO.GUIA AND PA.DATA = PARTICIPACAO.DATA
GROUP BY PA.ATRACAO;