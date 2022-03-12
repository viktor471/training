import pytest

class TestPrepare:
    """
    Этот тест -- и не тест вовсе: его нужно выполнить, чтоб заполнить БД всеми необходимыми сущностями для работы биддера
    и для его тестирования.
    """
    @pytest.mark.manual
    def test_fill_db(self, db, prepare_db, httpserver_listen_address):
        print("manual test fill bd")
        # db.query_from_file('pytest.sql', {'@URL@': httpserver_url})
