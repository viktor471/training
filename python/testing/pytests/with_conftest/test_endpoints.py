import pytest
from utils.logger import Logger

class TestEndpoints:
    # @pytest.mark.smoketest
    def test_ssp_list(self,
                      ssp_def_ep,
                      ssp_mopub_ep,
                      ep_rtb_rtb_usd_ssp_list,
                      httpserver_listen_address):
        Logger().record_exec_order(type="test")

    @pytest.mark.smoketest
    def test_domain_allow_list(self,
                               ssp_def_ep,
                               ep_rtb_rtb_usd_domain_allow_list,
                               httpserver_listen_address):
        Logger().record_exec_order(type="test")
        Logger().record_arbitrary_log(msg=f"returned value from "
                                          f"ep_rtb_rtb_usd_domain_allow_list {ep_rtb_rtb_usd_domain_allow_list}")
