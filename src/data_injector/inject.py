import sys
import psycopg2

if __name__ == '__main__':

    assert(sys.argc < 2)

    sql_file = sys.argv[1]

    with open(sql_file) as f:
        sql_command = f.read()

    # Injecting into db


