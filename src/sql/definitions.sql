-- usuario{email, nome_completo, ident_nacional*, username*, biografia, senha*, pais, telefone, foto, bool_guia*, bool_turista*}

CREATE TABLE USUARIO (
    EMAIL VARCHAR(50),
    NOME_COMPLETO VARCHAR(50),
    IDENT_NACIONAL VARCHAR(50),
    USERNAME VARCHAR(50),
    BIOGRAFIA VARCHAR(140), -- We like twitter
    SENHA VARCHAR(50),
    PAIS VARCHAR(50),
    TELEFONE VARCHAR(50),
    FOTO VARCHAR(50),
    BOOL_GUIA BOOLEAN,
    BOOL_TURISTA BOOLEAN,

    CONSTRAINT PK_USUARIO PRIMARY KEY (EMAIL)
);

-- mensagem{usuario_envia, usuario_recebe, mensagem*, data}

CREATE TABLE MENSAGEM (
    USUARIO_ENVIA VARCHAR(50),
    USUARIO_RECEBE VARCHAR(50),
    MENSAGEM VARCHAR(280), -- We like twitter
    DATA DATE,

    CONSTRAINT FK_USR_REC FOREIGN KEY (USUARIO_ENVIA) REFERENCES USUARIO(EMAIL),
    CONSTRAINT FK_USR_ENV FOREIGN KEY (USUARIO_RECEBE) REFERENCES USUARIO(EMAIL)
);

-- usuario_idioma{usuario, idioma}

CREATE TABLE USUARIO_IDIOMA (
    USUARIO VARCHAR(50),
    IDIOMA VARCHAR(50),

    CONSTRAINT FK_USUARIO_IDIOMA FOREIGN KEY (USUARIO) REFERENCES USUARIO(EMAIL),
    CONSTRAINT PK_USR_IDIOMA PRIMARY KEY (USUARIO, IDIOMA) -- So users can have multiple languages
);

-- relato_de_bug_print{usuario, data, print}

CREATE TABLE RELATO_DE_BUG_PRINT ();

-- relato_de_bug{usuario, data, status*, mensagem, log_de_erro*, tipo_de_erro*,tecnico}

CREATE TABLE RELATO_DE_BUG ();

--relato_de_viagem{usuario, data, status*, mensagem, tipo*, atendente, participacao*}

CREATE TABLE RELATO_DE_VIAGEM ();

-- relato_de_viagem_denuncia{usuario, data, usuario_denunciado}

CREATE TABLE RELATO_DE_VIAGEM_DENUNCIA ();

-- fotos_participacao{participacao, foto}

CREATE TABLE FOTOS_PARTICIPACAO (
    PARTICIPACAO VARCHAR(50),
    FOTO VARCHAR(50),
    CONSTRAINT PK_ATR_CAT PRIMARY KEY (PARTICIPACAO, FOTO)
);

-- participacao{NroParticipacao, guia*, data*, turista*}

CREATE TABLE PARTICIPACAO ();

-- avaliacao_guia{participacao, comentario*, nota*}

CREATE TABLE AVALIACAO_GUIA ();

-- avaliacao_turista{participacao, titulo*, comentario*, nota*}

CREATE TABLE AVALIACAO_TURISTA ();

--     tecnico{email, nome*, senha*, telefone, enfase}

CREATE TABLE TECNICO ();

--     atendente{email, nome*, senha*, telefone}

CREATE TABLE ATENDENTE ();

-- guia{usuario}

CREATE TABLE GUIA (
    USUARIO VARCHAR(50),

    CONSTRAINT FK_GUIA FOREIGN KEY (USUARIO) REFERENCES USUARIO(EMAIL) ON DELETE CASCADE,
    CONSTRAINT PK_GUIA PRIMARY KEY (USUARIO)
);

-- turista{usuario}

CREATE TABLE TURISTA (
     USUARIO VARCHAR(50),

     CONSTRAINT FK_TURISTA FOREIGN KEY (USUARIO) REFERENCES USUARIO(EMAIL) ON DELETE CASCADE,
     CONSTRAINT PK_TURISTA PRIMARY KEY (USUARIO)
);

-- turista_gosta{turista, atracao}

CREATE TABLE TURISTA_GOSTA (
    TURISTA VARCHAR(50),
    ATRACAO VARCHAR(50),
    CONSTRAINT PK_ATR_CAT PRIMARY KEY (TURISTA, ATRACAO)
);

-- passeio{guia, data, idioma*, titulo*, descricao*, pais, cidade, latitude*, longitude*, referencia, preco*, vagas*}

CREATE TABLE PASSEIO (
    GUIA VARCHAR(50),
    DATA DATE,
    IDIOMA VARCHAR(50) NOT NULL,
    TITULO VARCHAR(50) NOT NULL,
    DESCRICAO VARCHAR(280) NOT NULL,
    PAIS VARCHAR(50),
    CIDADE VARCHAR(50),
    LATITUDE VARCHAR(50) NOT NULL,
    LONGITUDE VARCHAR(50) NOT NULL,
    REFERENCIA VARCHAR(50),
    PRECO FLOAT,
    VAGAS INT,

    CONSTRAINT PK_PASSEIO PRIMARY KEY (GUIA, DATA),
    CONSTRAINT FK_PASSEIO FOREIGN KEY (GUIA) REFERENCES GUIA ON DELETE CASCADE
);

-- passeio_atracao{guia, data, atracao}

CREATE TABLE PASSEIO_ATRACAO ();

-- fotos_passeio{guia, data, foto}

CREATE TABLE FOTOS_PASSEIO (
    ATRACAO VARCHAR(50), --TODO CHANGE TO FK PASSEIO
    FOTO VARCHAR(50),
    CONSTRAINT PK_ATR_CAT PRIMARY KEY (ATRACAO, FOTO)
);

-- atracao{nome, referencia, longitude*, latitude*, pais, cidade, status_validacao*, data_validacao, atendente_validacao, palavra_chave1, palavra_chave2, palavra_chave3}

CREATE TABLE ATRACAO ();

-- fotos_atracao{atracao, foto}

CREATE TABLE FOTOS_ATRACAO (
    ATRACAO VARCHAR(50),
    FOTO VARCHAR(50),
    CONSTRAINT PK_FOTOS_ATR PRIMARY KEY (ATRACAO, FOTO)
);

-- atracao_categoria{atracao, categoria}

CREATE TABLE ATRACAO_CATEGORIA (
    ATRACAO VARCHAR(50),
    CATEGORIA VARCHAR(50),
    CONSTRAINT PK_ATR_CAT PRIMARY KEY (ATRACAO, CATEGORIA)
);

-- categoria{nome}

CREATE TABLE CATEGORIA (
    NOME VARCHAR(50),
    CONSTRAINT PK_CATEGORIA PRIMARY KEY (NOME)
);
