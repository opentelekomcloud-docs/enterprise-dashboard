.. -*- rst -*-

Health
======

.. rest_method:: GET /v2/health

This endpoint is used to get the API's health. There is no authentication required and results are not cached. It's used for monitoring the health of our service.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/health-get-curl
   :language: bash

Response Parameters
-------------------

N/A
