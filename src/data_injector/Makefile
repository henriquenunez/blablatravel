SQL_DIR = ../sql

all: create_venv
	echo Creating Venv...
	#python

definitions:
	python injector.py $(SQL_DIR)/definitions.sql

data:
	python injector.py $(SQL_DIR)/data.sql

drop:
	python injector.py $(SQL_DIR)/drop.sql

create_venv:
	python -m venv injector-v
	#source injector-v/bin/activate
	#pip install -m requirements.txt

activate: create_venv
	( \
       		source injector-v/vin/activate; \
       		pip install -r requirements.txt; \
       )

