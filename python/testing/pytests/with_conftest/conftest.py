import pytest
a = 0

@pytest.fixture(scope="session", autouse=True)
def dsp_router(request):
    
    print("begin fixture session dsp_router, a:", a)
    yield
    print("end fixture session dsp_router, a:", a)

@pytest.fixture(scope="session")
def ssp_def_ep():

    print("fixture ssp_def_ep, a:", a)

@pytest.fixture(scope="session")
def ssp_unity_ep():

    print("fixture session ssp_unity_ep, a:", a)

@pytest.fixture(scope="session")
def ssp_unity_ep():

    print("fixture session ssp_unity_ep, a:", a)

@pytest.fixture(scope="session")
def ssp_mopub_ep():

    print("fixture session ssp_mobup_ep, a:", a)

@pytest.fixture(scope="session")
def ssp_doubleverify_ep():

    print("fixture session ssp_doubleverify_ep, a:", a)

@pytest.fixture(scope="session")
def db():

    print("fixture session db, a:", a)

@pytest.fixture(scope="session")
def prepare_db(db):

    print("fixture session prepare_db, a:", a)

def check_plan_updated(db):

    print("check_plan_updated, a:", a)

@pytest.fixture(scope="function")
def ep_direct_vast(db):

    print("begin fixture function ep_direct_vast, a:", a)
    yield
    print("end fixture function ep_direct_vast, a:", a)

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd(db):

    print("begin fixture function ep_rtb_rtb_usd, a:", a)
    yield print("end fixture function ep_rtb_rtb_usd, a:", a)

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_no_extra_fields(db):

    print("begin fixture function ep_rtb_rtb_usd_no_extra_fields, a:", a)
    yield print("end fixture function ep_rtb_rtb_usd_no_extra_fields, a:", a)


@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_limit_req_daily(db):

    print("begin fixture function ep_rtb_rtb_usd_limit_req_daily, a:", a)
    yield print("end fixture function ep_rtb_rtb_usd_limit_req_daily, a:", a)

@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_ssp_list(db):

    print("begin fixture session ep_rtb_rtb_usd_ssp_list, a:", a)
    yield print("end fixture session ep_rtb_rtb_usd_ssp_list, a:", a)

@pytest.fixture(scope="session")
def ep_rtb_rtb_usd_domain_allow_list(db):

    print("begin fixture session ep_rtb_rtb_usd_domain_allow_list, a:", a)
    yield print("end fixture session ep_rtb_rtb_usd_domain_allow_list, a:", a)

@pytest.fixture(scope="function")
def ep_rtb_rtb_usd_cache_v2(db):

    print("begin fixture function ep_rtb_rtb_usd_cache_v2, a:", a)
    yield print("begin fixture function ep_rtb_rtb_usd_cache_v2, a:", a)

@pytest.fixture(scope="function")
def ep_rtb_rtb_rew(db):

    print("begin fixture function ep_rtb_rtb_rew, a:", a)
    yield print("begin fixture function ep_rtb_rtb_rew, a:", a)

@pytest.fixture(scope="function")
def ep_rtb_rtb_rub(db):

    print("begin fixture function ep_rtb_rtb_rub, a:", a)
    yield print("begin fixture function ep_rtb_rtb_rub, a:", a)

@pytest.fixture(scope="session")
def httpserver_listen_address():

    print("fixture session httpserver_listen_address, a:", a)
