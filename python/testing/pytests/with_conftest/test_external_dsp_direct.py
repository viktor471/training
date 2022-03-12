import pytest

class TestPrepare:
    @pytest.mark.manual
    def test_fill_db(self, db, prepare_db, httpserver_listen_address):
        print("manual test fill bd")
        # db.query_from_file('pytest.sql', {'@URL@': httpserver_url})
