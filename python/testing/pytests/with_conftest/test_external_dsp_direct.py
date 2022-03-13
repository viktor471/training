import pytest
from utils.logger import Logger

class TestPrepare:
    @pytest.mark.manual
    def test_fill_db(self,
                     db,
                     prepare_db,
                     httpserver_listen_address):
        Logger().record_exec_order(type="test")
