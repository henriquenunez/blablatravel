-- insert usuario
INSERT INTO USUARIO (EMAIL , NOME_COMPLETO, IDENT_NACIONAL, USERNAME, BIOGRAFIA, SENHA, PAIS, TELEFONE, FOTO, BOOL_GUIA, BOOL_TURISTA) 
    VALUES ('breno@gmail.com', 'Breno Cunha Queiroz', '404.518.940-81', 'brenocq', 'Brief biography about me', '1234', 'Brazil', '+55(16)982348577', 'https://avatars.githubusercontent.com/u/17342434?v=4', false, true);
INSERT INTO USUARIO (EMAIL , NOME_COMPLETO, IDENT_NACIONAL, USERNAME, BIOGRAFIA, SENHA, PAIS, TELEFONE, FOTO, BOOL_GUIA, BOOL_TURISTA) 
    VALUES ('dikson@gmail.com', 'Dikson Ferreira dos Santos', '518.054.130-15', 'diksown', 'Brief biography about me', '1234', 'Brazil', '+55(16)9823485788', NULL, true, false);
INSERT INTO USUARIO (EMAIL , NOME_COMPLETO, IDENT_NACIONAL, USERNAME, BIOGRAFIA, SENHA, PAIS, TELEFONE, FOTO, BOOL_GUIA, BOOL_TURISTA) 
    VALUES ('hiram@gmail.com', 'Henrique Hiram Libutti Nunez', '861.755.970-52', 'henriquenunez', 'Brief biography about me', '1234', 'Brazil', '+55(16)9823485788', NULL, true, true);
INSERT INTO USUARIO (EMAIL , NOME_COMPLETO, IDENT_NACIONAL, USERNAME, BIOGRAFIA, SENHA, PAIS, TELEFONE, FOTO, BOOL_GUIA, BOOL_TURISTA) 
    VALUES ('francisco@gmail.com', 'Francisco dos Reis', '792.692.070-30', 'franc', NULL, '1234', 'England', '+44(01)9823485781', NULL, true, true);

-- insert turista
INSERT INTO TURISTA (USUARIO) VALUES ('dikson@gmail.com');
INSERT INTO TURISTA (USUARIO) VALUES ('hiram@gmail.com');
INSERT INTO TURISTA (USUARIO) VALUES ('francisco@gmail.com');

-- insert guia
INSERT INTO GUIA (USUARIO) VALUES ('breno@gmail.com');
INSERT INTO GUIA (USUARIO) VALUES ('hiram@gmail.com');
INSERT INTO GUIA (USUARIO) VALUES ('francisco@gmail.com');

-- insert mensagem
INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA) 
    VALUES ('breno@gmail.com', 'dikson@gmail.com', 'A roupa roeu o rato do rei de roma', TO_TIMESTAMP('2021/07/12 08:12:11', 'YYYY/MM/DD HH24:MI:SS'));
INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA) 
    VALUES ('breno@gmail.com', 'hiram@gmail.com', 'Pedra dura agua mole tanto bate ate que fura', TO_TIMESTAMP('2021/07/12 08:13:15', 'YYYY/MM/DD HH24:MI:SS'));
INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA) 
    VALUES ('dikson@gmail.com', 'hiram@gmail.com', 'Que passeio legal!', TO_TIMESTAMP('2021/07/13 12:33:12', 'YYYY/MM/DD HH24:MI:SS'));
INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA) 
    VALUES ('hiram@gmail.com', 'dikson@gmail.com', 'Daora ne? :)', TO_TIMESTAMP('2021/07/13 12:33:16', 'YYYY/MM/DD HH24:MI:SS'));
INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA) 
    VALUES ('francisco@gmail.com', 'dikson@gmail.com', 'Oi dikson! A gente vai pro mesmo passeio ne?', TO_TIMESTAMP('2021/08/09 14:21:19', 'YYYY/MM/DD HH24:MI:SS'));
     
-- insert usuario_idioma
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('breno@gmail.com', 'Portuguese');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('breno@gmail.com', 'English');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('dikson@gmail.com', 'German');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('dikson@gmail.com', 'Portuguese');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('hiram@gmail.com', 'English');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('hiram@gmail.com', 'Spanish');
INSERT INTO USUARIO_IDIOMA (USUARIO, IDIOMA) VALUES ('hiram@gmail.com', 'Portuguese');
     
-- insert tecnico
INSERT INTO TECNICO (EMAIL, NOME, SENHA, TELEFONE, ENFASE) VALUES ('maria@gmail.com', 'Maria Eulalia', '1234', '+55(11)987872345', 'Database');
INSERT INTO TECNICO (EMAIL, NOME, SENHA, TELEFONE, ENFASE) VALUES ('carlos@gmail.com', 'Carlos Jose', '1234', NULL, 'SQL');
INSERT INTO TECNICO (EMAIL, NOME, SENHA, TELEFONE, ENFASE) VALUES ('edson@gmail.com', 'Edson batista', '1234', NULL, 'SGBD');
INSERT INTO TECNICO (EMAIL, NOME, SENHA, TELEFONE, ENFASE) VALUES ('julia@gmail.com', 'Julia Reis', '1234', '+55(11)777872345', 'Mobile Developer');

-- insert atendente
INSERT INTO ATENDENTE (EMAIL, NOME, SENHA, TELEFONE) VALUES ('jose@gmail.com', 'Jose Campos', '1234', NULL);
INSERT INTO ATENDENTE (EMAIL, NOME, SENHA, TELEFONE) VALUES ('ellen@gmail.com', 'Ellen da Silva', '1234', '+55(11)987222345');
INSERT INTO ATENDENTE (EMAIL, NOME, SENHA, TELEFONE) VALUES ('mauricio@gmail.com', 'Mauricio Beta', '1234', NULL);
INSERT INTO ATENDENTE (EMAIL, NOME, SENHA, TELEFONE) VALUES ('john@gmail.com', 'John Ferreiro', '1234', '+55(11)987872378');

-- insert passeio
INSERT INTO PASSEIO (GUIA, DATA, IDIOMA, TITULO, DESCRICAO, PAIS, CIDADE, LATITUDE, LONGITUDE, REFERENCIA, PRECO, VAGAS)
    VALUES ('breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'English', 'Christ the Redeemer', 
    'Created by French sculptor Paul Landowski and built by Brazilian engineer Heitor da Silva Costa', 'Brazil', 'Rio de Janeiro', 
    '-22.9519867', '-43.210986', 'On top of the mountain', 30, 10);
INSERT INTO PASSEIO (GUIA, DATA, IDIOMA, TITULO, DESCRICAO, PAIS, CIDADE, LATITUDE, LONGITUDE, REFERENCIA, PRECO, VAGAS)
    VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'Portuguese', 'Torre Eiffel', 
    'Torre treliça de ferro do século XIX', NULL, 'Paris', 
    '48.8583701', '2.2922926', NULL, 20, 40);
INSERT INTO PASSEIO (GUIA, DATA, IDIOMA, TITULO, DESCRICAO, PAIS, CIDADE, LATITUDE, LONGITUDE, REFERENCIA, PRECO, VAGAS)
    VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/05 09:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'English', 'Tower of London', 
    'Officially Her Majesty''s Royal Palace and Fortress of the Tower of London', NULL, NULL, 
    '51.5081157', '-0.078138', NULL, 80, 5);
    
-- insert atracao
INSERT INTO ATRACAO (NOME, REFERENCIA, LONGITUDE, LATITUDE, PAIS, CIDADE, STATUS_VALIDACAO, DATA_VALIDACAO, ATENDENTE_VALIDACAO, PALAVRA_CHAVE_1, PALAVRA_CHAVE_2, PALAVRA_CHAVE_3)
    VALUES ('Eiffel Towerr', NULL, '48.8583701', '2.2922926', 'France', 'Paris', 'EM_ESPERA', NULL, NULL, 'Tower', 'Building', NULL);
INSERT INTO ATRACAO (NOME, REFERENCIA, LONGITUDE, LATITUDE, PAIS, CIDADE, STATUS_VALIDACAO, DATA_VALIDACAO, ATENDENTE_VALIDACAO, PALAVRA_CHAVE_1, PALAVRA_CHAVE_2, PALAVRA_CHAVE_3)
    VALUES ('Eiffel Tower', NULL, '48.8583701', '2.2922926', 'France', 'Paris', 'ACEITO',  TO_TIMESTAMP('2021/02/25 12:11:30', 'YYYY/MM/DD HH24:MI:SS'), 'john@gmail.com', 'Tower', 'Building', NULL);
INSERT INTO ATRACAO (NOME, REFERENCIA, LONGITUDE, LATITUDE, PAIS, CIDADE, STATUS_VALIDACAO, DATA_VALIDACAO, ATENDENTE_VALIDACAO, PALAVRA_CHAVE_1, PALAVRA_CHAVE_2, PALAVRA_CHAVE_3)
    VALUES ('Christ the Redeemer',  'On top of the mountain', '-22.9519867', '-43.210986', 'Brazil', 'Rio de Janeiro', 
    'ACEITO', TO_TIMESTAMP('2021/02/27 13:11:30', 'YYYY/MM/DD HH24:MI:SS'), 'ellen@gmail.com', 'Tower', 'Building', NULL);
INSERT INTO ATRACAO (NOME, REFERENCIA, LONGITUDE, LATITUDE, PAIS, CIDADE, STATUS_VALIDACAO, DATA_VALIDACAO, ATENDENTE_VALIDACAO, PALAVRA_CHAVE_1, PALAVRA_CHAVE_2, PALAVRA_CHAVE_3)
    VALUES ('My house',  'Near MC Donalds', '-11', '-22', 'United States', 'San Francisco', 
    'REJEITADO', TO_TIMESTAMP('2021/02/28 17:13:31', 'YYYY/MM/DD HH24:MI:SS'), 'john@gmail.com', NULL, NULL, NULL);
    
-- insert passeio_atracao
INSERT INTO PASSEIO_ATRACAO (GUIA, DATA, ATRACAO) VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'Eiffel Tower');
INSERT INTO PASSEIO_ATRACAO (GUIA, DATA, ATRACAO) VALUES ('breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'Christ the Redeemer');

-- insert fotos_passeio
INSERT INTO FOTOS_PASSEIO(GUIA,  DATA, FOTO) VALUES ('breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'),
    'https://veja.abril.com.br/wp-content/uploads/2016/05/rio-equipe-do-google-street-view-subiu-o-morro-do-corcovado-com-cameras-em-uma-mochila-original.jpeg');
INSERT INTO FOTOS_PASSEIO(GUIA,  DATA, FOTO) VALUES ('breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'), 
    'http://www.adf.org.br/home/wp-content/uploads/2015/09/Cristo-Redentor-1.jpeg');
INSERT INTO FOTOS_PASSEIO(GUIA,  DATA, FOTO) VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), 
    'https://images.educamaisbrasil.com.br/content/banco_de_imagens/guia-de-estudo/D/torre-eiffel-iluminada.jpg');
    
-- insert turista_gosta
INSERT INTO TURISTA_GOSTA (TURISTA, ATRACAO) VALUES ('dikson@gmail.com', 'Eiffel Tower');
INSERT INTO TURISTA_GOSTA (TURISTA, ATRACAO) VALUES ('dikson@gmail.com', 'Christ the Redeemer');
INSERT INTO TURISTA_GOSTA (TURISTA, ATRACAO) VALUES ('hiram@gmail.com', 'Christ the Redeemer');

-- insert fotos_atracao
INSERT INTO FOTOS_ATRACAO (ATRACAO, FOTO) VALUES ('Eiffel Tower', 'https://images.educamaisbrasil.com.br/content/banco_de_imagens/guia-de-estudo/D/torre-eiffel-iluminada.jpg');
INSERT INTO FOTOS_ATRACAO (ATRACAO, FOTO) VALUES ('Christ the Redeemer', 'http://www.adf.org.br/home/wp-content/uploads/2015/09/Cristo-Redentor-1.jpeg');
INSERT INTO FOTOS_ATRACAO (ATRACAO, FOTO) VALUES ('Christ the Redeemer', 'https://veja.abril.com.br/wp-content/uploads/2016/05/rio-equipe-do-google-street-view-subiu-o-morro-do-corcovado-com-cameras-em-uma-mochila-original.jpeg');

-- insert categoria
INSERT INTO CATEGORIA (NOME) VALUES ('Building');
INSERT INTO CATEGORIA (NOME) VALUES ('Nature');
INSERT INTO CATEGORIA (NOME) VALUES ('History');
INSERT INTO CATEGORIA (NOME) VALUES ('Adventure');
INSERT INTO CATEGORIA (NOME) VALUES ('Cultural');

-- insert atracao_categoria
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Eiffel Tower', 'Building');
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Eiffel Tower', 'History');
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Eiffel Tower', 'Cultural');
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Christ the Redeemer', 'History');
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Christ the Redeemer', 'Building');
INSERT INTO ATRACAO_CATEGORIA (ATRACAO, CATEGORIA) VALUES ('Christ the Redeemer', 'Adventure');

-- insert participacao
INSERT INTO PARTICIPACAO (NRO_PARTICIPACAO, GUIA, DATA, TURISTA) VALUES (1,'hiram@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'dikson@gmail.com');
INSERT INTO PARTICIPACAO (NRO_PARTICIPACAO, GUIA, DATA, TURISTA) VALUES (2,'breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'dikson@gmail.com');
INSERT INTO PARTICIPACAO (NRO_PARTICIPACAO, GUIA, DATA, TURISTA) VALUES (3,'hiram@gmail.com', TO_TIMESTAMP('2021/08/05 09:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'dikson@gmail.com');
INSERT INTO PARTICIPACAO (NRO_PARTICIPACAO, GUIA, DATA, TURISTA) VALUES (4,'breno@gmail.com', TO_TIMESTAMP('2021/08/10 14:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'hiram@gmail.com');
INSERT INTO PARTICIPACAO (NRO_PARTICIPACAO, GUIA, DATA, TURISTA) VALUES (5,'hiram@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), 'francisco@gmail.com');

-- insert relato_de_viagem
INSERT INTO RELATO_DE_VIAGEM (USUARIO, DATA, STATUS, MENSAGEM, TIPO, ATENDENTE, PARTICIPACAO) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/08/11 15:01:00', 'YYYY/MM/DD HH24:MI:SS'), 'PENDENTE', 'Ele nao foi gentil', 'DENUNCIA', NULL, 1);
INSERT INTO RELATO_DE_VIAGEM (USUARIO, DATA, STATUS, MENSAGEM, TIPO, ATENDENTE, PARTICIPACAO) 
    VALUES ('francisco@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:01', 'YYYY/MM/DD HH24:MI:SS'), 'PENDENTE', 'Ele foi grosso', 'DENUNCIA', NULL, 1);
INSERT INTO RELATO_DE_VIAGEM (USUARIO, DATA, STATUS, MENSAGEM, TIPO, ATENDENTE, PARTICIPACAO) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/08/11 15:01:24', 'YYYY/MM/DD HH24:MI:SS'), 'EM_ANALISE', NULL, 'OBJETO_PERDIDO', 'ellen@gmail.com', 1);
INSERT INTO RELATO_DE_VIAGEM (USUARIO, DATA, STATUS, MENSAGEM, TIPO, ATENDENTE, PARTICIPACAO) 
    VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/10 14:24:23', 'YYYY/MM/DD HH24:MI:SS'), 'RESOLVIDO', 'Eu me perdi e partiram sem mim, deveriam ter me esperado!', 'OUTRO', 'mauricio@gmail.com', 4);
INSERT INTO RELATO_DE_VIAGEM (USUARIO, DATA, STATUS, MENSAGEM, TIPO, ATENDENTE, PARTICIPACAO) 
    VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/08/10 16:32:11', 'YYYY/MM/DD HH24:MI:SS'), 'EM_ANALISE', 'Acho que meu SDR ficou com o guia...', 'OBJETO_PERDIDO', 'john@gmail.com', 4);
    
-- insert relato_de_bug
INSERT INTO RELATO_DE_BUG (USUARIO, DATA, STATUS, MENSAGEM, LOG_DE_ERRO, TIPO_DE_ERRO, TECNICO) 
    VALUES ('breno@gmail.com', TO_TIMESTAMP('2021/07/13 03:33:33', 'YYYY/MM/DD HH24:MI:SS'), 'EM_ANALISE', 
    'A tela do celular comecou a piscar sem parar...', '/src/env/deamon.hpp -- error solid state active background', 'SYSTEM CRASH', 'maria@gmail.com');
INSERT INTO RELATO_DE_BUG (USUARIO, DATA, STATUS, MENSAGEM, LOG_DE_ERRO, TIPO_DE_ERRO, TECNICO) 
    VALUES ('hiram@gmail.com', TO_TIMESTAMP('2021/07/15 12:11:01', 'YYYY/MM/DD HH24:MI:SS'), 'PENDENTE', 
    NULL, 'Segmentation fault... <log>', 'SYSTEM CRASH', NULL);
INSERT INTO RELATO_DE_BUG (USUARIO, DATA, STATUS, MENSAGEM, LOG_DE_ERRO, TIPO_DE_ERRO, TECNICO) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/07/11 16:11:01', 'YYYY/MM/DD HH24:MI:SS'), 'RESOLVIDO', 
    NULL, 'WARN: Implict cast from std::set to float', 'CASTING', 'edson@gmail.com');
    
-- insert relato_de_bug_print
INSERT INTO RELATO_DE_BUG_PRINT (USUARIO, DATA, PRINT) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/07/11 16:11:01', 'YYYY/MM/DD HH24:MI:SS'), 'https://www.castgroup.com.br/wp-content/uploads/2020/07/logo-ok.png');
INSERT INTO RELATO_DE_BUG_PRINT (USUARIO, DATA, PRINT) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/07/11 16:11:01', 'YYYY/MM/DD HH24:MI:SS'), 'https://www.mairovergara.com/wp-content/uploads/2018/12/16-Cast-Out-1.jpg');
INSERT INTO RELATO_DE_BUG_PRINT (USUARIO, DATA, PRINT) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/07/11 16:11:01', 'YYYY/MM/DD HH24:MI:SS'), 'https://i.pinimg.com/originals/89/40/37/8940375635fd33e202a7fda7346fbc7e.png');

-- insert relato_de_viagem_denuncia
INSERT INTO RELATO_DE_VIAGEM_DENUNCIA (USUARIO, DATA, USUARIO_DENUNCIADO) 
    VALUES ('dikson@gmail.com', TO_TIMESTAMP('2021/08/11 15:01:00', 'YYYY/MM/DD HH24:MI:SS'), 'hiram@gmail.com');
INSERT INTO RELATO_DE_VIAGEM_DENUNCIA (USUARIO, DATA, USUARIO_DENUNCIADO) 
    VALUES ('francisco@gmail.com', TO_TIMESTAMP('2021/08/11 15:00:01', 'YYYY/MM/DD HH24:MI:SS'), 'hiram@gmail.com');

-- insert fotos_participacao
INSERT INTO FOTOS_PARTICIPACAO (PARTICIPACAO, FOTO) VALUES (2, 'https://www.riodejaneiro.com/media/uploads/riodejaneiro.com/2015/07/Christ%20the%20Redeemer.jpg');
INSERT INTO FOTOS_PARTICIPACAO (PARTICIPACAO, FOTO) VALUES (4, 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRnrZo0oYb7EAzJp0KFGBoz48GyrRiS_9ZHBgF6Im7sEY9obtGY-G48a3_IpPkpMTEak04&usqp=CAU');
INSERT INTO FOTOS_PARTICIPACAO (PARTICIPACAO, FOTO) VALUES (4, 'https://www.albomadventures.com/wp-content/uploads/2019/05/visti-Christ-the-redeemer-PC300063.jpg');
INSERT INTO FOTOS_PARTICIPACAO (PARTICIPACAO, FOTO) VALUES (4, 'https://rederiohoteis.com/wp-content/uploads/2017/09/2017-10-29-cristo-redentor-conhe%C3%A7a-a-historia-dessa-maravilha-do-mundo-moderno2-1280x720.jpg');

-- insert avaliacao_guia
INSERT INTO AVALIACAO_GUIA (PARTICIPACAO, COMENTARIO, NOTA) VALUES (1, 'Ficava correndo pra todo lado', 3);
INSERT INTO AVALIACAO_GUIA (PARTICIPACAO, COMENTARIO, NOTA) VALUES (2, 'He was very nice, just a bit strange', 5);
INSERT INTO AVALIACAO_GUIA (PARTICIPACAO, COMENTARIO, NOTA) VALUES (3, 'Cool guy', 4);

-- insert avaliacao_turista
INSERT INTO AVALIACAO_TURISTA (PARTICIPACAO, TITULO, COMENTARIO, NOTA) VALUES (1, 'Muito Legal!', 'Ele ficou reclamando das pessoas', 5);
INSERT INTO AVALIACAO_TURISTA (PARTICIPACAO, TITULO, COMENTARIO, NOTA) VALUES (2, 'Pretty Statue', 'Noice, I liked', 4);
INSERT INTO AVALIACAO_TURISTA (PARTICIPACAO, TITULO, COMENTARIO, NOTA) VALUES (3, 'Nice', 'Good guy', 5);

