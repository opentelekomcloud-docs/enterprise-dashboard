.. -*- rst -*-

.. warning::

   **Attention** 
   API endpoint v1/grafana/user/orgs is deprecated.

   Use the API provided by Grafana.

This API allows you to manage Grafana Organization:

- Get organizations for user
- Get current organization
- Switch user context to the given organization

Please use your username and password as basic authentificaton for Grafana API endpoints. These credentials are also used to log into the UI.

Get Organization for user
=========================

.. rest_method:: GET /v1/grafana/user/orgs

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/orgs-list-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/orgs-list-response.json
   :language: javascript

Get Current organization
========================

.. rest_method:: GET /v1/grafana/user/orgs/current

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/orgs-current-get-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/orgs-current-get-response.json
   :language: javascript

Switch user context to the given organization
=============================================

.. rest_method:: GET /v1/grafana/user/using/1

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/orgs-switch-curl
   :language: bash

Response Parameters
-------------------

Response Example
----------------

.. literalinclude:: examples/orgs-switch-response.json
   :language: javascript
