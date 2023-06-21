.. -*- rst -*-

.. warning::

   **Attention** 
   API endpoint /v1/Grafana/keys is deprecated
   
   Use the API provided by Grafana.
   This API allows you to manage Grafana API keys: https://enterprise-dashboard-dev.otc-service.com/api/auth/keys
   
   Documentation: 
   https://grafana.com/docs/grafana/latest/administration/api-keys/


This API allows you to manage Grafana API keys:

- List keys
- Create API key
- Delete key

Please use your username and password as basic authentificaton for Grafana API endpoints. These credentials are also used to log into the UI.

List Keys
=========

.. rest_method:: GET /v1/Grafana/keys

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/api_key-list-curl
   :language: bash

Response Parameters
-------------------

N/A

Reponse Example
---------------

.. literalinclude:: examples/api_key-list-response.json
   :language: javascript

Create Key
==========

.. rest_method:: POST /v1/Grafana/keys

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

.. rest_parameters:: ../parameters.yaml

   - name: key_name

Curl Example
------------

.. literalinclude:: examples/api_key-create-curl
   :language: bash

Response Parameters
-------------------

N/A

Reponse Example
---------------

.. literalinclude:: examples/api_key-create-response.json
   :language: javascript

Delete Key
==========

.. rest_method:: DELETE /v1/Grafana/keys

.. rest_status_code:: success ../http-status.yaml

   - 204

.. rest_status_code:: error ../http-status.yaml

   - 400

Request
-------

N/A

Curl Example
------------

.. literalinclude:: examples/api_key-delete-curl
   :language: bash

Response Parameters
-------------------

N/A

Reponse Example
---------------

N/A
