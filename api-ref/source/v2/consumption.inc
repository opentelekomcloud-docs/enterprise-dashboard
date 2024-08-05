.. -*- rst -*-

Show Consumption
================

.. rest_method:: GET /v2/hourly/consumption

This API fetches your consumption data. Please create a API Key either in Enterprise Dashboard UI or with the API.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - contract: contract
   - date: date
   - show_tag: show_tag
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - tag_key: tag_key
   - tag_value: tag_value
   - hour: hour
   - week: week
   - month: month
   - year: year

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

.. rest_method:: GET /v1/consumption

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

