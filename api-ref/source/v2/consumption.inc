Show Consumption (Hourly Granularity)
=====================================

.. rest_method:: GET /v2/hourly/consumption

This API streams your consumption data in batches of 1,000 records. The response is returned as a string, with each line representing a valid JSON object. You'll need to decode each line and parse it into JSON format on your end.

Please ensure you create an API Key either through the Enterprise Dashboard UI or via the Grafana API directly.

Note: API uses 'Europe/Berlin' as default timezone for parameters and response. If the same request is made with identical parameters within 1 hour, cached data will be returned instead of fresh data.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 422

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - consumption_type: consumption_type
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

Example request using curl with query parameters and headers:

.. literalinclude:: examples/consumption-hourly-get-curl
   :language: bash

Response Parameters
-------------------

Response Example (converted to JSON from byte string)
-----------------------------------------------------

.. literalinclude:: examples/consumption-get-hourly-response.json
   :language: javascript

Python Example
--------------

Example showing how to stream and parse the response in Python:

.. literalinclude:: examples/consumption-get-hourly.py
   :language: python


Show Consumption (Daily Granularity)
====================================

.. rest_method:: GET /v2/daily/consumption

This API streams your consumption data in batches of 1,000 records. The response is returned as a string, with each line representing a valid JSON object. You'll need to decode each line and parse it into JSON format on your end.

Please ensure you create an API Key either through the Enterprise Dashboard UI or via the Grafana API directly.

Note: API uses 'Europe/Berlin' as default timezone for parameters and response. If the same request is made with identical parameters within 1 hour, cached data will be returned instead of fresh data.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 422

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - consumption_type: consumption_type
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

Example request using curl with query parameters and headers:

.. literalinclude:: examples/consumption-daily-get-curl
   :language: bash

Response Parameters
-------------------

Response Example (converted to JSON from byte string)
-----------------------------------------------------

.. literalinclude:: examples/consumption-get-daily-response.json
   :language: javascript

Python Example
--------------

Example showing how to stream and parse the response in Python:

.. literalinclude:: examples/consumption-get-daily.py
   :language: python
