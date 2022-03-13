import pytest
from utils.logger import Logger

@pytest.fixture(scope="session", autouse=True)
def dsp_router(request):
    Logger().record_exec_order(position="begin", scope="session", autouse=True)
    yield "dsp_router returned value"
    Logger().record_exec_order(position="end", scope="session", autouse=True)

@pytest.fixture(scope="session")
def ssp_def_ep():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def ssp_unity_ep():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def ssp_unity_ep():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def ssp_mopub_ep():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def ssp_doubleverify_ep():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def db():
    Logger().record_exec_order(scope="session")

@pytest.fixture(scope="session")
def prepare_db(db):
    Logger().record_exec_order(scope="session")

def check_plan_updated(db):
    Logger().record_arbitrary_log("check_plan_updated", add_to_exec_log=True)

@pytest.fixture(scope="function")
def ep_direct_vast(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_direct_vast returned value"
    Logger().record_exec_order(position="end", scope="function")


@pytest.fixture(scope="function")
def ep_rtb_rtb_usd(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_usd returned value"
    Logger().record_exec_order(position="end", scope="function")

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_no_extra_fields(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_usd_no_extra_fields return value"
    Logger().record_exec_order(position="end", scope="function")

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_limit_req_daily(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_usd_limit_req_daily returned value"
    Logger().record_exec_order(position="end", scope="function")


@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_ssp_list(db):
    Logger().record_exec_order(position="begin", scope="session")
    yield "ep_rtb_rtb_usd_ssp_list return value"
    Logger().record_exec_order(position="end", scope="session")


@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_domain_allow_list(db):
    Logger().record_exec_order(position="begin", scope="session")
    yield "ep_rtb_rtb_usd_domain_allow_list returned value"
    Logger().record_exec_order(position="end", scope="session")


@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_cache_v2(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_usd_cache_v2 returned value"
    Logger().record_exec_order(position="end", scope="function")


@pytest.fixture(scope="function")
def ep_rtb_rtb_rew(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_rew returned value"
    Logger().record_exec_order(position="end", scope="function")


@pytest.fixture(scope="function")
def ep_rtb_rtb_rub(db):
    Logger().record_exec_order(position="begin", scope="function")
    yield "ep_rtb_rtb_rub returned value"
    Logger().record_exec_order(position="end", scope="function")


@pytest.fixture(scope="session")
def httpserver_listen_address():
    Logger().record_exec_order(scope="session")
