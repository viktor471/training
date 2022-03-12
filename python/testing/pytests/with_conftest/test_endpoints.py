import logging

import pytest
import time
from werkzeug import Response

# from pytests.bidder.rtb_requests import *
# from pytests.bidder.rtb_tools import RtbRequest, Currency
# from pytests.config import BANKER_URL
# from pytests.utils.curl import Curl
# import requests
# import os


class TestEndpoints:
    # @pytest.mark.smoketest
    def test_ssp_list(self, ssp_def_ep, ssp_mopub_ep, ep_rtb_rtb_usd_ssp_list, httpserver_listen_address, httpserver):
        """
        """
        ssp_def_ep
        ssp_mopub_ep
        ep_rtb_rtb_usd_ssp_list
        httpserver_listen_address
        httpserver

    @pytest.mark.smoketest
    def test_domain_allow_list(self, ssp_def_ep, ep_rtb_rtb_usd_domain_allow_list, httpserver_listen_address):
        print(ep_rtb_rtb_usd_domain_allow_list)
        print(ssp_def_ep)
        print(ssp_def_ep)
