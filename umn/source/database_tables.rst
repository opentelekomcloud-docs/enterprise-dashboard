Database table structure
========================

Enterprise Dashboard uses a PostgreSQL 15 Database which has certain
tables to use.

The tables are described in the following. Based on those tables you
can create your own widgets and queries. The creation of new widgets
and dashboards is available for Editor or Admin Users of an
organization.


Business.consumption_daily
~~~~~~~~~~~~~~~~~~~~~~~~~~

This table represents your billing data according to your Open Telekom
Cloud invoice (except limitations listed in chapter Current
Limitations):

+---------------------------+----------------------+----------------------+
| Field name                | Data type            | Description          |
+===========================+======================+======================+
| contract                  | Int8                 | Your contract id     |
+---------------------------+----------------------+----------------------+
| consumption_date          | timestamp            | Date when the        |
|                           |                      | billing item was     |
|                           |                      | created / when you   |
|                           |                      | consumed the service |
+---------------------------+----------------------+----------------------+
| quantity_type             | varchar              | This field displays  |
|                           |                      | the unit for the     |
|                           |                      | billing items.       |
+---------------------------+----------------------+----------------------+
| quantity                  | Float8               | The quantity of the  |
|                           |                      | item which has to be |
|                           |                      | interpreted in       |
|                           |                      | combination with the |
|                           |                      | unit field,          |
|                           |                      | e.g. "10.GB".        |
+---------------------------+----------------------+----------------------+
| amount                    | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | Euro, same as        |
|                           |                      | Price*Quantity.      |
|                           |                      | Including discounts  | 
|                           |                      | and vouchers         |
+---------------------------+----------------------+----------------------+
| product                   | varchar              | This field displays  |
|                           |                      | the produt_id        |
|                           |                      | In case you need     |
|                           |                      | more product details |
|                           |                      | you have to join     |
|                           |                      | in business.product  | 
|                           |                      | table.               |
+---------------------------+----------------------+----------------------+
| product_description       | varchar              | The name of the      |
|                           |                      | product              |
+---------------------------+----------------------+----------------------+
| project_id                | varchar              | The project id       |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| project_name              | varchar              | The project name     |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| resource_id               | varchar              | The resource_id      |
|                           |                      | of the service       |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| consumption_type          | varchar              | The type of dataset  |
|                           |                      | which can be:        |
|                           |                      |                      |
|                           |                      | Cost types:          |
|                           |                      |                      |
|                           |                      | -  K017 & K018       |
|                           |                      |    elastic prices    |
|                           |                      |                      |
|                           |                      | -  D102 advance      |
|                           |                      |    payments          |
|                           |                      |                      |
|                           |                      | -  D103& D536        |
|                           |                      |    monthly payments  |
|                           |                      |                      |
|                           |                      | -  D104 allowances   |
|                           |                      |                      |
|                           |                      | -  D537 free amount  |
|                           |                      |    of a monthly      |
|                           |                      |    payment e.g. of a |
|                           |                      |    reserved package  |
|                           |                      |                      |
|                           |                      | Discount types:      |
|                           |                      |                      |
|                           |                      | -  R100 applied      |
|                           |                      |    discount          |
|                           |                      |                      |
|                           |                      | -  R400 enterprise   |
|                           |                      |    discount          |
|                           |                      |                      |
+---------------------------+----------------------+----------------------+
| aggregation_id            | varchar              | Unique identifier    |
|                           |                      | for a row            |
+---------------------------+----------------------+----------------------+
| region                    | varchar              | The name of the      |
|                           |                      | region to which a    |
|                           |                      | resource belongs     |
|                           |                      | (e.g. 'eu-de')       |
+---------------------------+----------------------+----------------------+


Business.consumption_hourly
~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table represents your billing data according to your Open Telekom
Cloud invoice (except limitations listed in chapter Current
Limitations):

+---------------------------+----------------------+----------------------+
| Field name                | Data type            | Description          |
+===========================+======================+======================+
| contract                  | Int8                 | Your contract id     |
+---------------------------+----------------------+----------------------+
| consumption_date          | timestamp            | Date when the        |
|                           |                      | billing item was     |
|                           |                      | created / when you   |
|                           |                      | consumed the service |
+---------------------------+----------------------+----------------------+
| quantity_type             | varchar              | This field displays  |
|                           |                      | the unit for the     |
|                           |                      | billing items.       |
+---------------------------+----------------------+----------------------+
| quantity                  | Float8               | The quantity of the  |
|                           |                      | item which has to be |
|                           |                      | interpreted in       |
|                           |                      | combination with the |
|                           |                      | unit field,          |
|                           |                      | e.g. "10.GB".        |
+---------------------------+----------------------+----------------------+
| amount                    | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | Euro, same as        |
|                           |                      | Price*Quantity.      |
|                           |                      | Including discounts  | 
|                           |                      | and vouchers         |
+---------------------------+----------------------+----------------------+
| amount_exluding_discount  | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | total cost before    |
|                           |                      | the discounts are    |
|                           |                      | applied.             |
+---------------------------+----------------------+----------------------+
| product                   | varchar              | This field displays  |
|                           |                      | the product_id       |
|                           |                      | In case you need     |
|                           |                      | more product details |
|                           |                      | you have to join     |
|                           |                      | in business.product  | 
|                           |                      | table.               |
+---------------------------+----------------------+----------------------+
| product_description       | varchar              | The name of the      |
|                           |                      | product              |
+---------------------------+----------------------+----------------------+
| project_id                | varchar              | The project id       |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| project_name              | varchar              | The project name     |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| resource_id               | varchar              | The resource_id      |
|                           |                      | of the service       |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| bill_cycle_day            | varchar              | Billing calculation  |
|                           |                      | cycle typically      | 
|                           |                      | daily or 1           |
+---------------------------+----------------------+----------------------+
| consumption_type          | varchar              | The type of dataset  |
|                           |                      | which can be:        |
|                           |                      |                      |
|                           |                      | Cost types:          |
|                           |                      |                      |
|                           |                      | -  K017 & K018       |
|                           |                      |    elastic prices    |
|                           |                      |                      |
|                           |                      | -  D102 advance      |
|                           |                      |    payments          |
|                           |                      |                      |
|                           |                      | -  D103& D536        |
|                           |                      |    monthly payments  |
|                           |                      |                      |
|                           |                      | -  D104 allowances   |
|                           |                      |                      |
|                           |                      | -  D537 free amount  |
|                           |                      |    of a monthly      |
|                           |                      |    payment e.g. of a |
|                           |                      |    reserved package  |
|                           |                      |                      |
|                           |                      | Discount types:      |
|                           |                      |                      |
|                           |                      | -  R100 applied      |
|                           |                      |    discount          |
|                           |                      |                      |
|                           |                      | -  R400 enterprise   |
|                           |                      |    discount          |
|                           |                      |                      |
+---------------------------+----------------------+----------------------+
| usage_id                  | varchar              | Unique identifier    |
|                           |                      | for a row            |
+---------------------------+----------------------+----------------------+
| region                    | varchar              | The name of the      |
|                           |                      | region to which a    |
|                           |                      | resource belongs     |
|                           |                      | (e.g. 'eu-de')       |
+---------------------------+----------------------+----------------------+



Business.product
~~~~~~~~~~~~~~~~

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| id                   | varchar              | The ID of the         |
|                       |                      | product used in the  |
|                       |                      | T-Systems billing    |
|                       |                      | system               |
+-----------------------+----------------------+----------------------+
| description           | varchar              | The description of   |
|                       |                      | the product          |
+-----------------------+----------------------+----------------------+
| category              | String               | The category of the  |
|                       |                      | the product, used in |
|                       |                      | the T-Systems        |
|                       |                      | billing system.      |
|                       |                      |                      |
|                       |                      | There are the        |
|                       |                      | following            |
|                       |                      | categories:          |
|                       |                      |                      |
|                       |                      | -  Compute           |
|                       |                      |                      |
|                       |                      | -  Network           |
|                       |                      |                      |
|                       |                      | -  PaaS              |
|                       |                      |                      |
|                       |                      | -  SaaS              |
|                       |                      |                      |
|                       |                      | -  Management        |
|                       |                      |                      |
|                       |                      | -  Storage           |
|                       |                      |                      |
+-----------------------+----------------------+----------------------+
| family                | String               | The product family   |
|                       |                      | of a service         |
+-----------------------+----------------------+----------------------+


Business.tag_daily
~~~~~~~~~~~~~~~~~~

This table gives you a list of tag keys and tag values, which are
pairs. This table is used in Tagging dashboards to access dashboards
fast. The initial load is slow depending on the amount of data it
needs to query to fill these variables.

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| contract              | numeric              | Your contract id     |
+-----------------------+----------------------+----------------------+
| aggregation           | varchar              | Key for internal     |
|                       |                      | purposes             |
+-----------------------+----------------------+----------------------+
| key                   | varchar              | The tag keys which   |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| value                 | varchar              | The tag values which |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+


Business.tag_hourly
~~~~~~~~~~~~~~~~~~~

This table gives you a list of tag keys and tag values, which are
pairs. This table is used in Tagging dashboards to access dashboards
fast. The initial load is slow depending on the amount of data it
needs to query to fill these variables.

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| contract              | numeric              | Your contract id     |
+-----------------------+----------------------+----------------------+
| aggregation           | varchar              | Key for internal     |
|                       |                      | purposes             |
+-----------------------+----------------------+----------------------+
| key                   | varchar              | The tag keys which   |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| value                 | varchar              | The tag values which |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+

Business.contract
~~~~~~~~~~~~~~~~~

This table gives you a list of contract-IDs for your
payer account ID. This table is used in Payer
dashboards in order to access dashboards with shower query execution time.
The initial load is slow depending on the amount of data it needs to query 
to fill this variable. Searching for all distinct contract IDs in
business.consumption_daily has the same result as Business.contract, but 
thequery itself will be resolved much quicker due to smaller datasets.

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| business_partner_id   | Int8                 | Your business        |
|                       |                      | partner id           |
+-----------------------+----------------------+----------------------+
| business_partner_name | varchar              | The name of your     |
|                       |                      | organisation /       |
|                       |                      | business partner     |
+-----------------------+----------------------+----------------------+
| id                    | Int8                 | Your contract id     |
+-----------------------+----------------------+----------------------+
| name                  | varchar              | The name of your     |
|                       |                      | contract or          |
|                       |                      | organisation. In     |
|                       |                      | order to edit this   |
|                       |                      | name please get in   |
|                       |                      | touch with the       |
|                       |                      | dashboard squad,     |
|                       |                      | contact with the     |
|                       |                      | dashboard squad for  |
|                       |                      | this.                |
+-----------------------+----------------------+----------------------+
| currency              | varchar              | Currency used for    |
|                       |                      | billing.             | 
+-----------------------+----------------------+----------------------+
| address_city          | varchar              | City part of the     | 
|                       |                      | address.             | 
+-----------------------+----------------------+----------------------+
| address_country       | varchar              | Country part of the  | 
|                       |                      | address.             | 
+-----------------------+----------------------+----------------------+
| address_name          | varchar              | Name part of the a   | 
|                       |                      | address.             | 
+-----------------------+----------------------+----------------------+
| address_postcode      | varchar              | Postcode part of the | 
|                       |                      | address.             | 
+-----------------------+----------------------+----------------------+
| billing_email         | varchar              | Email used for       |
|                       |                      | billing.             | 
+-----------------------+----------------------+----------------------+
| status                | varchar              | status               |
+-----------------------+----------------------+----------------------+
| time_zone             | varchar              | Time zone            |
+-----------------------+----------------------+----------------------+


Business.dim_ol_capacity_ecs_compute
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table is only available if you use Enterprise Dashboard Extra
Large. It's possible to receive Capacity data of your Open Telekom
Cloud Hybrid in Enterprise Dashboard. The actual availability of data
sets depends on your Hybrid Installation. Data is exported once per
day. The “timestamp” attribute shows when the data was collected.

+-------------------------+----------------------+-----------------------+
| Field name              | Data type            | Description           |
+=========================+======================+=======================+
| service                 | varchar              | Indicates the service |
|                         |                      | name, which           |
|                         |                      | identifies the        |
|                         |                      | service to which a    |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| timestamp               | timestamp            | Indicates the time    |
|                         |                      | stamp in Unix format, |
|                         |                      | e.g. 1598306400000.   |
+-------------------------+----------------------+-----------------------+
| region                  | varchar              | Indicates the name of |
|                         |                      | the region to which a |
|                         |                      | resource belongs,     |
|                         |                      | e.g. eu-de.           |
+-------------------------+----------------------+-----------------------+
| az                      | varchar              | Indicates the name of |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs,     |
|                         |                      | e.g. eu-de-01.        |
+-------------------------+----------------------+-----------------------+
| zone                    | varchar              | Indicates the POD to  |
|                         |                      | which a resource      |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| cluster                 | varchar              | Indicates the cluster |
|                         |                      | to which a resource   |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| host                    | varchar              | None.                 |
+-------------------------+----------------------+-----------------------+
| resource_type           | varchar              | Indicates the         |
|                         |                      | resource type, e.g.   |
|                         |                      | s2.                   |
+-------------------------+----------------------+-----------------------+
| type                    | varchar              | Indicates the data    |
|                         |                      | type. ECS resource    |
|                         |                      | data types are as     |
|                         |                      | follows:              |
|                         |                      | vCpu, memory, vGpu,   |
|                         |                      | and vmTotal.          |
+-------------------------+----------------------+-----------------------+
| total                   | float8               | Indicates the total   |
|                         |                      | number of resources   |
|                         |                      | (vCPU: number;        |
|                         |                      | Memory: TB; vGPU:     |
|                         |                      | number).              |
+-------------------------+----------------------+-----------------------+
| used                    | float8               | Indicates the number  |
|                         |                      | of the used resources |
|                         |                      | (vCPU: number;        |
|                         |                      | Memory: TB; vGPU:     |
|                         |                      | number).              |
+-------------------------+----------------------+-----------------------+
| free                    | float8               | Indicates the number  |
|                         |                      | of the remaining      |
|                         |                      | resources (vCPU:      |
|                         |                      | number; Memory: TB;   |
|                         |                      | vGPU: number).        |
+-------------------------+----------------------+-----------------------+
| allocated               | float8               | Indicates the number  |
|                         |                      | of the allocated      |
|                         |                      | resources (vCPU:      |
|                         |                      | number; Memory: TB;   |
|                         |                      | vGPU: number).        |
+-------------------------+----------------------+-----------------------+
| spot_allocated          | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| containerAllocated      | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| available               | float8               | Indicates the number  |
|                         |                      | of the available      |
|                         |                      | resources (vCPU:      |
|                         |                      | number; Memory: TB;   |
|                         |                      | vGPU: number).        |
+-------------------------+----------------------+-----------------------+
| used_ratio              | float8               | Indicates the         |
|                         |                      | resource usage.       |
+-------------------------+----------------------+-----------------------+
| allocated_ratio         | float8               | Indicates the         |
|                         |                      | resource allocation   |
|                         |                      | rate.                 |
+-------------------------+----------------------+-----------------------+
| over_subscription_ratio | float8               | None                  |
|                         |                      |                       |
+-------------------------+----------------------+-----------------------+
| additional_info         | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| region_id               | varchar              | Indicates the region  |
|                         |                      | ID to which a         |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az_id                   | varchar              | Indicates the ID of   |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| zone_type               | varchar              | Indicates the         |
|                         |                      | resource type to      |
|                         |                      | which a resource      |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| Host_group              | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| host_total              | int4                 | Number of resources   |
|                         |                      | in total              |
+-------------------------+----------------------+-----------------------+
| etl_created             | timestamp            | Displays when this    |
|                         |                      | data set was created. |
+-------------------------+----------------------+-----------------------+


Business.dim_ol_capacity_ecs_vm
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table is only available if you use Enterprise Dashboard Extra
Large. It’s possible to receive Capacity data of your Open Telekom
Cloud Hybrid in Enterprise Dashboard. The actual availability of data
sets depends on your Hybrid Installation. Data is exported once per
day. The “timestamp” attribute shows when the data was collected.

+-------------------------+----------------------+-----------------------+
| Field name              | Data type            | Description           |
+=========================+======================+=======================+
| service                 | varchar              | Indicates the service |
|                         |                      | name, which           |
|                         |                      | identifies the        |
|                         |                      | service to which a    |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| timestamp               | timestamp            | Indicates the time    |
|                         |                      | stamp in Unix format, |
|                         |                      | e.g. 1598306400000    |
+-------------------------+----------------------+-----------------------+
| region                  | varchar              | Indicates the name of |
|                         |                      | the region to which a |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az                      | varchar              | Indicates the name of |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| zone                    | varchar              | Indicates the POD to  |
|                         |                      | which a resource      |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| cluster                 | varchar              | Indicates the name of |
|                         |                      | the cluster to which  |
|                         |                      | a resource belongs.   |
+-------------------------+----------------------+-----------------------+
| host                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| resource_type           | varchar              | Indicates the         |
|                         |                      | resource type, e.g.   |
|                         |                      | s2.8xlarge.2          |
+-------------------------+----------------------+-----------------------+
| type                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| total                   | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| used                    | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| free                    | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| allocated               | float8               | Indicates the number  |
|                         |                      | of allocated          |
|                         |                      | resources. Unit: VM.  |
+-------------------------+----------------------+-----------------------+
| spot_allocated          | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| containerAllocated      | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| available               | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| used_ratio              | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| allocated_ratio         | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| over_subscription_ratio | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| additional_info         | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| flavor_vCpu             | float8               | Indicates the number  |
|                         |                      | of vCpu               |
+-------------------------+----------------------+-----------------------+
| flavor_mem              | float8               | Indicates the amount  |
|                         |                      | of memory in GB       |
+-------------------------+----------------------+-----------------------+
| is_public               | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| region_id               | varchar              | Indicates the region  |
|                         |                      | ID to which a         |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az_id                   | varchar              | Indicates the ID of   |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| zone_type               | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| host_total              | int4                 | None                  |
+-------------------------+----------------------+-----------------------+
| etl_created             | timestamp            | Displays when this    |
|                         |                      | data set was created  |
+-------------------------+----------------------+-----------------------+

Business.dim_ol_capacity_evs_capacity
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table is only available if you use Enterprise Dashboard Extra
Large. It’s possible to receive Capacity data of your Open Telekom
Cloud Hybrid in Enterprise Dashboard. The actual availability of data
sets depends on your Hybrid Installation. Data is exported once per
day. The “timestamp” attribute shows when the data was collected.

+-------------------------+----------------------+-----------------------+
| Field name              | Data type            | Description           |
+=========================+======================+=======================+
| service                 | varchar              | Indicates the service |
|                         |                      | name, which           |
|                         |                      | identifies the        |
|                         |                      | service to which a    |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| timestamp               | timestamp            | Indicates the time    |
|                         |                      | stamp in Unix format, |
|                         |                      | e.g. 1598306400000    |
+-------------------------+----------------------+-----------------------+
| region                  | varchar              | Indicates the name of |
|                         |                      | the region to which a |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az                      | varchar              | Indicates the name of |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| zone                    | varchar              | Indicates the POD to  |
|                         |                      | which a resource      |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| cluster                 | varchar              | Indicates the storage |
|                         |                      | pool to which the     |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| host                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| resource_type           | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| type                    | varchar              | Indicates the data    |
|                         |                      | type. EVS data types  |
|                         |                      | are as follows:       |
|                         |                      |                       |
|                         |                      | SATA, SAS, and SSD    |
+-------------------------+----------------------+-----------------------+
| total                   | float8               | Indicates the total   |
|                         |                      | number of resources.  |
|                         |                      | Unit: TB.             |
+-------------------------+----------------------+-----------------------+
| used                    | float8               | Indicates the number  |
|                         |                      | of used resources.    |
|                         |                      | Unit: TB.             |
+-------------------------+----------------------+-----------------------+
| free                    | float8               | Indicates the         |
|                         |                      | remaining number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| allocated               | float8               | Indicates the         |
|                         |                      | allocated number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| spot_allocated          | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| containerAllocated      | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| available               | float8               | Indicates the number  |
|                         |                      | of available          |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| used_ratio              | float8               | Indicates the         |
|                         |                      | resource usage        |
+-------------------------+----------------------+-----------------------+
| allocated_ratio         | float8               | Indicates the         |
|                         |                      | resource allocation   |
|                         |                      | rate.                 |
+-------------------------+----------------------+-----------------------+
| over_subscription_ratio | float8               | Indicates the         |
|                         |                      | overcommitment ratio. |
+-------------------------+----------------------+-----------------------+
| additional_info         | varchar              |                       |
+-------------------------+----------------------+-----------------------+
| sata_physical_host      | varchar              | Indicates the number  |
|                         |                      | of SATA PMs. Unit:    |
|                         |                      | PCs                   |
+-------------------------+----------------------+-----------------------+
| ssd_physical_host       | varchar              | Indicates the number  |
|                         |                      | of SSD PMs. Unit: PCs |
+-------------------------+----------------------+-----------------------+
| sas_physical_host       | varchar              | Indicates the number  |
|                         |                      | of SAS PMs. Unit: PCs |
+-------------------------+----------------------+-----------------------+
| pool_model              | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| region_id               | varchar              | Indicates the ID of   |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| zone_type               | varchar              | Indicates the         |
|                         |                      | resource type to      |
|                         |                      | which a resource      |
|                         |                      | belongs               |
+-------------------------+----------------------+-----------------------+
| etl_created             | timestamp            | Displays when this    |
|                         |                      | data set was created  |
+-------------------------+----------------------+-----------------------+

Business.dim_ol_capacity_obs
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table is only available if you use Enterprise Dashboard Extra
Large. It’s possible to receive Capacity data of your Open Telekom
Cloud Hybrid in Enterprise Dashboard. The actual availability of data
sets depends on your Hybrid Installation. Data is exported once per
day. The “timestamp” attribute shows when the data was collected.

+-------------------------+----------------------+-----------------------+
| Field name              | Data type            | Description           |
+=========================+======================+=======================+
| service                 | varchar              | Indicates the service |
|                         |                      | name, which           |
|                         |                      | identifies the        |
|                         |                      | service to which a    |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| timestamp               | timestamp            | Indicates the time    |
|                         |                      | stamp in Unix format, |
|                         |                      | e.g. 1598306400000    |
+-------------------------+----------------------+-----------------------+
| region                  | varchar              | Indicates the name of |
|                         |                      | the region to which a |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az                      | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| zone                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| cluster                 | varchar              | Indicates the cluster |
|                         |                      | to which a resource   |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| host                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| resource_type           | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| type                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| total                   | float8               | Indicates the total   |
|                         |                      | number of resources.  |
|                         |                      | Unit: TB.             |
+-------------------------+----------------------+-----------------------+
| used                    | float8               | Indicates the         |
|                         |                      | remaining number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| free                    | float8               | Indicates the         |
|                         |                      | remaining number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| allocated               | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| spot_allocated          | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| containerAllocated      | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| available               | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| used_ratio              | float8               | Indicates the         |
|                         |                      | resource usage.       |
+-------------------------+----------------------+-----------------------+
| allocated_ratio         | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| over_subscription_ratio | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| additional_info         | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| logic_total             | varchar              | Indicates the total   |
|                         |                      | logic capacity. Unit: |
|                         |                      | TB.                   |
+-------------------------+----------------------+-----------------------+
| logic_used              | varchar              | Indicates the number  |
|                         |                      | of used logic. Unit:  |
|                         |                      | TB.                   |
+-------------------------+----------------------+-----------------------+
| zone_type               | varchar              |                       |
+-------------------------+----------------------+-----------------------+
| host_total              | int4                 |                       |
+-------------------------+----------------------+-----------------------+
| etl_created             | timestamp            | Displays when this    |
|                         |                      | data set was created  |
+-------------------------+----------------------+-----------------------+

Business.dim_ol_capacity_eip
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table is only available if you use Enterprise Dashboard Extra
Large. It’s possible to receive Capacity data of your Open Telekom
Cloud Hybrid in Enterprise Dashboard. The actual availability of data
sets depends on your Hybrid Installation. Data is exported once per
day. The “timestamp” attribute shows when the data was collected.

+-------------------------+----------------------+-----------------------+
| Field name              | Data type            | Description           |
+=========================+======================+=======================+
| service                 | varchar              | Indicates the service |
|                         |                      | name, which           |
|                         |                      | identifies the        |
|                         |                      | service to which a    |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| timestamp               | timestamp            | Indicates the time    |
|                         |                      | stamp in Unix format, |
|                         |                      | e.g. 1598306400000    |
+-------------------------+----------------------+-----------------------+
| region                  | varchar              | Indicates the name of |
|                         |                      | the region to which a |
|                         |                      | resource belongs.     |
+-------------------------+----------------------+-----------------------+
| az                      | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| zone                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| cluster                 | varchar              | Indicates the cluster |
|                         |                      | to which a resource   |
|                         |                      | belongs.              |
+-------------------------+----------------------+-----------------------+
| host                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| resource_type           | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| type                    | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| total                   | float8               | Indicates the total   |
|                         |                      | number of resources.  |
|                         |                      | Unit: TB.             |
+-------------------------+----------------------+-----------------------+
| used                    | float8               | Indicates the         |
|                         |                      | remaining number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| free                    | float8               | Indicates the         |
|                         |                      | remaining number of   |
|                         |                      | resources. Unit: TB.  |
+-------------------------+----------------------+-----------------------+
| allocated               | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| spot_allocated          | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| containerAllocated      | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| available               | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| used_ratio              | float8               | Indicates the         |
|                         |                      | resource usage.       |
+-------------------------+----------------------+-----------------------+
| allocated_ratio         | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| over_subscription_ratio | float8               | None                  |
+-------------------------+----------------------+-----------------------+
| additional_info         | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| region_id               | varchar              | Indicates the ID of   |
|                         |                      | the AZ to which a     |
|                         |                      | resource belongs      |
+-------------------------+----------------------+-----------------------+
| az_id                   | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| zone_type               | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| status                  | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| subType                 | varchar              | None                  |
+-------------------------+----------------------+-----------------------+
| etl_created             | timestamp            | Displays when this    |
|                         |                      | data set was created  |
+-------------------------+----------------------+-----------------------+
