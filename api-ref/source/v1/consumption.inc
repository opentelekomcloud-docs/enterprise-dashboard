.. -*- rst -*-

Show Consumption
================

.. rest_method:: GET /v1/consumption

This API fetches your consumption data. Please create a API Key either in Enterprise Dashboard UI or with the API.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - limit: limit
   - offset: offset
   - contract: contract
   - consumption_date: consumption_date
   - tagged: tagged
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - tag_key: tag_key
   - tag_value: tag_value

Curl Example
------------

.. literalinclude:: examples/consumption-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-get-response.json
   :language: javascript

Show Daily Consumption
======================

.. rest_method:: GET /v1/consumption/day

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - consumption_date: consumption_date-query

Curl Example
------------

.. literalinclude:: examples/consumption-day-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-day-get-response.json
   :language: javascript

Show Weekly Consumption
=======================

.. rest_method:: GET /v1/consumption/day

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - year: year
   - week: week

Curl Example
------------

.. literalinclude:: examples/consumption-week-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-week-get-response.json
   :language: javascript

Show Montly Consumption
=======================

.. rest_method:: GET /v1/consumption/month

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - month: month

Curl Example
------------

.. literalinclude:: examples/consumption-month-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-month-get-response.json
   :language: javascript

Show Reserved packages data
===========================

.. rest_method:: GET /v1/consumption/reserved

This API fetches your reserved packages data.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - contract: contract

Curl Example
------------

.. literalinclude:: examples/consumption-reserved-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/consumption-reserved-get-response.json
   :language: javascript

