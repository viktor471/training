import pytest

@pytest.fixture(scope="session", autouse=True)
def dsp_router(request):
    print("begin fixture session dsp_router, a:")
    yield
    print("end fixture session dsp_router:")

@pytest.fixture(scope="session")
def ssp_def_ep():
    print("fixture ssp_def_ep:")

@pytest.fixture(scope="session")
def ssp_unity_ep():
    print("fixture session ssp_unity_ep:")

@pytest.fixture(scope="session")
def ssp_unity_ep():
    print("fixture session ssp_unity_ep:")

@pytest.fixture(scope="session")
def ssp_mopub_ep():
    print("fixture session ssp_mobup_ep:")

@pytest.fixture(scope="session")
def ssp_doubleverify_ep():
    print("fixture session ssp_doubleverify_ep:")

@pytest.fixture(scope="session")
def db():
    print("fixture session db:")

@pytest.fixture(scope="session")
def prepare_db(db):
    print("fixture session prepare_db:")

def check_plan_updated(db):
    print("check_plan_updated:")

@pytest.fixture(scope="function")
def ep_direct_vast(db):
    print("begin fixture function ep_direct_vast:")
    yield
    print("end fixture function ep_direct_vast:")

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd(db):
    print("begin fixture function ep_rtb_rtb_usd:")
    yield print("end fixture function ep_rtb_rtb_usd:")

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_no_extra_fields(db):
    print("begin fixture function ep_rtb_rtb_usd_no_extra_fields:")
    yield print("end fixture function ep_rtb_rtb_usd_no_extra_fields:")


@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_limit_req_daily(db):
    print("begin fixture function ep_rtb_rtb_usd_limit_req_daily:")
    yield print("end fixture function ep_rtb_rtb_usd_limit_req_daily:")

@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_ssp_list(db):
    print("begin fixture session ep_rtb_rtb_usd_ssp_list:")
    yield print("end fixture session ep_rtb_rtb_usd_ssp_list:")

@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_domain_allow_list(db):
    print("begin fixture session ep_rtb_rtb_usd_domain_allow_list:")
    yield print("end fixture session ep_rtb_rtb_usd_domain_allow_list:")

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_cache_v2(db):
    print("begin fixture function ep_rtb_rtb_usd_cache_v2:")
    yield print("begin fixture function ep_rtb_rtb_usd_cache_v2:")

@pytest.fixture(scope="function")
def ep_rtb_rtb_rew(db):
    print("begin fixture function ep_rtb_rtb_rew:")
    yield print("begin fixture function ep_rtb_rtb_rew:")

@pytest.fixture(scope="function")
def ep_rtb_rtb_rub(db):
    print("begin fixture function ep_rtb_rtb_rub:")
    yield print("begin fixture function ep_rtb_rtb_rub:")

@pytest.fixture(scope="session")
def httpserver_listen_address():
    print("fixture session httpserver_listen_address:")
