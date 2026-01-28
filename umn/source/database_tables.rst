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
| aggregation_id            | varchar              | Unique identifier    |
|                           |                      | for a row            |
+---------------------------+----------------------+----------------------+
| project_id                | varchar              | The project id       |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| resource_id               | varchar              | The resource_id      |
|                           |                      | of the service       |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| contract                  | Int8                 | Your contract id     |
+---------------------------+----------------------+----------------------+
| quantity                  | Float8               | The quantity of the  |
|                           |                      | item which has to be |
|                           |                      | interpreted in       |
|                           |                      | combination with the |
|                           |                      | unit field,          |
|                           |                      | e.g. "10 GB".        |
+---------------------------+----------------------+----------------------+
| quantity_type             | varchar              | This field displays  |
|                           |                      | the unit for the     |
|                           |                      | billing items.       |
|                           |                      | Values are GB, h or  |
|                           |                      | pc.                  |
+---------------------------+----------------------+----------------------+
| consumption_date          | timestamp            | Date when the        |
|                           |                      | billing item was     |
|                           |                      | created / when you   |
|                           |                      | consumed the service |
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
| amount                    | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | Euro, same as        |
|                           |                      | Price*Quantity.      |
|                           |                      | Including discounts  | 
|                           |                      | and vouchers         |
+---------------------------+----------------------+----------------------+
| region                    | varchar              | The name of the      |
|                           |                      | region to which a    |
|                           |                      | resource belongs     |
|                           |                      | (e.g. 'eu-de')       |
+---------------------------+----------------------+----------------------+
| status                    | varchar              | Technical attribute  |
+---------------------------+----------------------+----------------------+
| etl_updated               | timestamp            | Technical attribute  |
|                           |                      | for invoice          |
+---------------------------+----------------------+----------------------+
| consumption_type          | varchar              | The type of dataset  |
|                           |                      | which can be:        |
|                           |                      |                      |
|                           |                      | Cost types:          |
|                           |                      |                      |
|                           |                      | -  EL                |
|                           |                      |    elastic prices    |
|                           |                      |                      |
|                           |                      | -  RC                |
|                           |                      |    reccuring charges |
|                           |                      |                      |
|                           |                      | -  OTF               |
|                           |                      |    one time fee      |
|                           |                      |                      |
+---------------------------+----------------------+----------------------+
| project_name              | varchar              | The project name     |
|                           |                      | where the service is |
|                           |                      | consumed             |
+---------------------------+----------------------+----------------------+


Business.consumption_hourly
~~~~~~~~~~~~~~~~~~~~~~~~~~~

This table represents your billing data according to your Open Telekom
Cloud invoice (except limitations listed in chapter Current
Limitations):

+---------------------------+----------------------+----------------------+
| Field name                | Data type            | Description          |
+===========================+======================+======================+
| usage_id                  | varchar              | Unique identifier    |
|                           |                      | for a row            |
+---------------------------+----------------------+----------------------+
| project_id                | varchar              | The project id       |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| resource_id               | varchar              | The resource_id      |
|                           |                      | of the service       |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+
| contract                  | Int8                 | Your contract id     |
+---------------------------+----------------------+----------------------+
| quantity                  | Float8               | The quantity of the  |
|                           |                      | item which has to be |
|                           |                      | interpreted in       |
|                           |                      | combination with the |
|                           |                      | unit field,          |
|                           |                      | e.g. "10.GB".        |
+---------------------------+----------------------+----------------------+
| quantity_type             | varchar              | This field displays  |
|                           |                      | the unit for the     |
|                           |                      | billing items.       |
|                           |                      | Values are GB, h or  |
|                           |                      | pc.                  |
+---------------------------+----------------------+----------------------+
| consumption_date          | timestamp            | Date when the        |
|                           |                      | billing item was     |
|                           |                      | created / when you   |
|                           |                      | consumed the service |
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
| external_priceplan        | varchar              | The name of the      |
|                           |                      | priceplan            |
+---------------------------+----------------------+----------------------+
| amount_excluding_discount | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | total cost before    |
|                           |                      | the discounts are    |
|                           |                      | applied.             |
+---------------------------+----------------------+----------------------+
| amount                    | Float8               | This field displays  |
|                           |                      | the actual costs in  |
|                           |                      | Euro, same as        |
|                           |                      | Price*Quantity.      |
|                           |                      | Including discounts  | 
|                           |                      | and vouchers         |
+---------------------------+----------------------+----------------------+
| bill_cycle_day            | varchar              | Billing calculation  |
|                           |                      | cycle typically      | 
|                           |                      | daily or 1           |
+---------------------------+----------------------+----------------------+
| region                    | varchar              | The name of the      |
|                           |                      | region to which a    |
|                           |                      | resource belongs     |
|                           |                      | (e.g. 'eu-de')       |
+---------------------------+----------------------+----------------------+
| status                    | varchar              | Technical attribute  |
+---------------------------+----------------------+----------------------+
| etl_updated               | timestamp            | Technical attribute  |
|                           |                      | for invoice          |
+---------------------------+----------------------+----------------------+
| consumption_type          | varchar              | The type of dataset  |
|                           |                      | which can be:        |
|                           |                      |                      |
|                           |                      | Cost types:          |
|                           |                      |                      |
|                           |                      | -  EL                |
|                           |                      |    elastic prices    |
|                           |                      |                      |
|                           |                      | -  RC                |
|                           |                      |    reccuring charges |
|                           |                      |                      |
|                           |                      | -  OTF               |
|                           |                      |    one time fee      |
|                           |                      |                      |
+---------------------------+----------------------+----------------------+
| project_name              | varchar              | The project name     |
|                           |                      | where the service is |
|                           |                      | consumed.            |
+---------------------------+----------------------+----------------------+





Business.product
~~~~~~~~~~~~~~~~

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
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
| changed_at            | timestamp            | Technical attribute  |
+-----------------------+----------------------+----------------------+
| created_at            | timestamp            | Technical attribute  |
+-----------------------+----------------------+----------------------+
| description           | varchar              | The description of   |
|                       |                      | the product          |
+-----------------------+----------------------+----------------------+
| family                | String               | The product family   |
|                       |                      | of a service         |
+-----------------------+----------------------+----------------------+
| hash_value            | varchar              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| id                    | varchar              | The ID of the        |
|                       |                      | product used in the  |
|                       |                      | T-Systems billing    |
|                       |                      | system               |
+-----------------------+----------------------+----------------------+
| lifecycle_status      | varchar              | "ACTIVE" or "RETIRED"|
+-----------------------+----------------------+----------------------+
| os                    | varchar              | Refers to the        |
|                       |                      | operating system, if |
|                       |                      | applicable           |
+-----------------------+----------------------+----------------------+
| ram                   | varchar              | Refers to the        |
|                       |                      | ram size, if         |
|                       |                      | applicable           |
+-----------------------+----------------------+----------------------+
| size                  | varchar              | Refers to the        |
|                       |                      | flavor size, if      |
|                       |                      | applicable           |
+-----------------------+----------------------+----------------------+
| source_id             | varchar              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| status                | varchar              | "ACTIVE" or "RETIRED"|
+-----------------------+----------------------+----------------------+
| vcpu                  | varchar              | Refers to number of  |
|                       |                      | vCPU, if applicable  |
+-----------------------+----------------------+----------------------+
| pc_de                 | float                | Power consumption    |
|                       |                      | coefficient, power   |
|                       |                      | consumption rate of  |
|                       |                      | product (kWh/unit)   |
|                       |                      | for Germany (DE)     |
+-----------------------+----------------------+----------------------+
| pc_nl                 | float                | Power consumption    |
|                       |                      | coefficient, power   |
|                       |                      | consumption rate of  |
|                       |                      | product (kWh/unit)   |
|                       |                      | for Netherlands (NL) |
+-----------------------+----------------------+----------------------+
| pc_ch2                | float                | Power consumption    |
|                       |                      | coefficient, power   |
|                       |                      | consumption rate of  |
|                       |                      | product (kWh/unit)   |
|                       |                      | for Switzerland(CH2) |
+-----------------------+----------------------+----------------------+
| ec_de                 | float                | CO₂ emission         |
|                       |                      | coefficient, carbon  |
|                       |                      | emission rate of     |
|                       |                      | product (kgCO₂/unit) |
|                       |                      | for Germany (DE)     |
+-----------------------+----------------------+----------------------+
| ec_nl                 | float                | CO₂ emission         |
|                       |                      | coefficient, carbon  |
|                       |                      | emission rate of     |
|                       |                      | product (kgCO₂/unit) |
|                       |                      | for Netherlands (NL) |
+-----------------------+----------------------+----------------------+
| ec_ch2                | float                | CO₂ emission         |
|                       |                      | coefficient, carbon  |
|                       |                      | emission rate of     |
|                       |                      | product (kgCO₂/unit) |
|                       |                      | for Switzerland(CH2) |
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
| id                    | numeric              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| aggregation_id        | varchar              | Aggregation id for   |
|                       |                      | tag                  |
+-----------------------+----------------------+----------------------+
| key                   | varchar              | The tag keys which   |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| value                 | varchar              | The tag values which |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| contract              | numeric              | Your contract id     |
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
| id                    | numeric              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| usage_id              | varchar              | Aggregation id for   |
|                       |                      | tag                  |
+-----------------------+----------------------+----------------------+
| key                   | varchar              | The tag keys which   |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| value                 | varchar              | The tag values which |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| contract              | numeric              | Your contract id     |
+-----------------------+----------------------+----------------------+

Business.reserved_packages
~~~~~~~~~~~~~~~~~~~~~~~~~~

This table gives you additional information about your additional
subscriptions, which can be reoccuring charges or one time fee's.
In the tables business.consumption_[daily/hourly] these datasets 
are distinguishable via the consumption type "RC" or "OTF".
Please note that this table is still work in progress.

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| key_id                | varchar              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| subscription_id       | varchar              | Technical attribute  |
+-----------------------+----------------------+----------------------+
| subscription_status   | varchar              | Indicates if the     |
|                       |                      | package is active or |
|                       |                      | expired              |
+-----------------------+----------------------+----------------------+
| subscription          | timestamp            | Date of booking      |
| _start_date           |                      |                      |
+-----------------------+----------------------+----------------------+
| subscription          | timestamp            | Termination of       |
| _end_date             |                      | booking              |
+-----------------------+----------------------+----------------------+
| subscription          | timestamp            | Technical attribute  |
| _effective_since      |                      |                      |
+-----------------------+----------------------+----------------------+
| subscription_next     | timestamp            | Technical attribute  |
| _effective_since      |                      |                      |
+-----------------------+----------------------+----------------------+
| subscription_changed  | timestamp            | Technical attribute  |
| _at                   |                      |                      |
+-----------------------+----------------------+----------------------+
| product_name          | varchar              | Same as product_id   |
+-----------------------+----------------------+----------------------+
| quantity              | Float8               | Number of individual |
|                       |                      | bookings             |
+-----------------------+----------------------+----------------------+
| price                 | Float8               | Price per unit.      |
|                       |                      | General price info.  |
|                       |                      | Individual price     |
|                       |                      | may differ           |
+-----------------------+----------------------+----------------------+
| bucket_id             | varchar              | Unique ID for each   | 
|                       |                      | free amount per      |
|                       |                      | month                | 
+-----------------------+----------------------+----------------------+
| filling_quantity      | numeric              | Already used free    | 
|                       |                      | amount               | 
+-----------------------+----------------------+----------------------+
| limit_quantity        | numeric              | Upper limit of free  | 
|                       |                      | amount               | 
+-----------------------+----------------------+----------------------+
| bucket_type           | varchar              | "Bucket" if free     | 
|                       |                      | amount of reserved   |
|                       |                      | package              |
+-----------------------+----------------------+----------------------+
| bucket_start_date     | timestamp            | Start date of a      | 
|                       |                      | bucket               |
+-----------------------+----------------------+----------------------+
| bucket_end_date       | timestamp            | End date of a        | 
|                       |                      | bucket               |
+-----------------------+----------------------+----------------------+
| bucket_exp_date       | timestamp            | End date of a        | 
|                       |                      | bucket               |
+-----------------------+----------------------+----------------------+
| contract              | Int8                 | Your contract id     |
+-----------------------+----------------------+----------------------+
| product_description   | varchar              | The name of the      |
|                       |                      | product              |
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
