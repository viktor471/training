from pydantic import BaseModel
from pprint import pprint
from typing import Any

class Fields(BaseModel):
    class Config:
        arbitrary_types_allowed = True

    def __getitem__(self, key):
        return dict(self)[key]

    def __setitem__(self, key, value):
        self.__dict__[key] = value
        return value

    def update(self, *models: list[BaseModel | dict]) -> "Fields":
        for model in models:
            if isinstance(model, BaseModel):
                updated_data = model.dict(exclude_unset=True)
            # else:
                # updated_data = model

            for key in updated_data.keys():
                self[key] = model[key]

        return self


class Dsp(BaseModel):
    id: int
    user_id: None | int
    currency_id: None | int
    name: None | str
    fee: None | float
    fee_at_2: None | float
    min_bid_floor: None | float
    adomain: None| str
    macros: None | str
    vars: None | str
    handler: None | str
    skip_zero_ifa: None | int
    limit_req_daily: None | int
    add_api: None | int
    status: None | str
    created: None | str
    updated: None | str


class PropertyModel(BaseModel):
    key: str
    name: str
    value: Any


class FixtureVars(Fields):
    crid: None | int
    dsp: None | Dsp
    property: None | PropertyModel

fv_1 = FixtureVars()
fv_1.dsp = Dsp(id = 1)
fv_1.crid = 4

fv_2 = FixtureVars()
fv_2.property = PropertyModel(key = "hello", name = "bye", value = 3)

fv_3 = FixtureVars()

fv_3.update(fv_1, fv_2)

print(type(fv_3.property))
pprint(fv_3.dict())



