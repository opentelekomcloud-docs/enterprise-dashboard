.. -*- rst -*-

Show Consumption (Hourly Granularity)
================

.. rest_method:: GET /v2/hourly/consumption

This API streams your consumption data with batch size of 1000. Please create a API Key either in Enterprise Dashboard UI or with the API. If request is sent with same parameters within 1 hr, cached data will be returned. 

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - contract: contract
   - date: date
   - hour: hour
   - month: month
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - show_tag: show_tag
   - tag_key: tag_key
   - tag_value: tag_value
   - week: week
   - year: year

Curl Example
------------

.. literalinclude:: examples/consumption-hourly-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-get-response.json
   :language: javascript


Show Consumption (Daily Granularity)
================

.. rest_method:: GET /v2/daily/consumption

This API streams your aggregated consumption data with batch size of 1000. Please create a API Key either in Enterprise Dashboard UI or with the API. If request is sent with same parameters within 1 hr, cached data will be returned. 

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - contract: contract
   - date: date
   - month: month
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - show_tag: show_tag
   - tag_key: tag_key
   - tag_value: tag_value
   - week: week
   - year: year

Curl Example
------------

.. literalinclude:: examples/consumption-daily-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-get-response.json
   :language: javascript

