Database table structure
========================

Enterprise Dashboard uses a PostgreSQL 10 Database which has certain
tables to use.

The tables are described in the following. Based on those tables you
can create your own widgets and queries. The creation of new widgets
and dashboards is available for Editor or Admin Users of an
organization.


Business.consumption
~~~~~~~~~~~~~~~~~~~~

This table represents your billing data according to your Open Telekom
Cloud invoice (except limitations listed in chapter Current
Limitations):

+---------------------------+----------------------+----------------------+
| Field name                | Data type            | Description          |
+===========================+======================+======================+
| consumption_date          | timestamp            | Date when the        |
|                           |                      | billing item was     |
|                           |                      | created / when you   |
|                           |                      | consumed the service |
+---------------------------+----------------------+----------------------+
| contract                  | Int8                 | Your contract id     |
+---------------------------+----------------------+----------------------+
| product                   | varchar              | The product used in  | 
|                           |                      | the T-Systems        |
|                           |                      | billing system       |
|                           |                      | (e.g. OTC_VPC_UP)    |
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
| billing_status            | Int8                 | the billing status   |
|                           |                      | which is 10 when     |
|                           |                      | invoiced and 0 when  |
|                           |                      | not invoiced         |
+---------------------------+----------------------+----------------------+
| business_partner_id       | Int8                 | Your business        |
|                           |                      | partner id           |
+---------------------------+----------------------+----------------------+
| business_partner_name     | varchar              | The name of your     |
|                           |                      | organisation /       |
|                           |                      | business partner     |
+---------------------------+----------------------+----------------------+
| quantity_unit             | varchar              | The unit for the     |
|                           |                      | billing items (e.g.  |
|                           |                      | 'H' for running      |
|                           |                      | of virtual machines  |
|                           |                      | or 'GB' for storage  |
|                           |                      | consumed by volumes) |
+---------------------------+----------------------+----------------------+
| unit_price                | Float8               | The price per        |
|                           |                      | quantity             |
+---------------------------+----------------------+----------------------+
| project_id                | varchar              | The id of the        |
|                           |                      | project where the    |
|                           |                      | service is consumed  |
+---------------------------+----------------------+----------------------+
| resource_id               | varchar              | The resource id of   |
|                           |                      | the service          |
+---------------------------+----------------------+----------------------+
| hash32                    | varchar              | Unique identifier    |
|                           |                      | for a row            |
+---------------------------+----------------------+----------------------+
| region                    | varchar              | The name of the      |
|                           |                      | region to which a    |
|                           |                      | resource belongs     |
|                           |                      | (e.g. 'eu-de')       |
+---------------------------+----------------------+----------------------+
| hash_key                  | varchar              | A Hash-Key for       |
|                           |                      | internal purposes    |
+---------------------------+----------------------+----------------------+
| fte_reseller_id           | Int4                 | The reseller id is   |
|                           |                      | used in certain      |
|                           |                      | organisation models, |
|                           |                      | you won't need       |
|                           |                      | this in most cases   |
+---------------------------+----------------------+----------------------+
| product_description       | varchar              | The name of the      |
|                           |                      | product              |
+---------------------------+----------------------+----------------------+
| project_name              | varchar              | The project name     |
|                           |                      | where the service is |
|                           |                      | consumed             |
+---------------------------+----------------------+----------------------+
| amount_excluding_discount | Float8               | The costs in EUR     |
|                           |                      | which equal to       |
|                           |                      | Price*Quantity.      |
|                           |                      | **Without**          |
|                           |                      | discounts and        |
|                           |                      | vouchers             |
+---------------------------+----------------------+----------------------+
| amount                    | Float8               | The actual costs in  | 
|                           |                      | EUR which equal to   |
|                           |                      | Price*Quantity.      |
|                           |                      | **Including**        |
|                           |                      | discounts and        |
|                           |                      | vouchers             |
+---------------------------+----------------------+----------------------+
| quantity                  | Float8               | The quantity of the  |
|                           |                      | item which has to be |
|                           |                      | interpreted in       |
|                           |                      | combination with the |
|                           |                      | unit field,          |
|                           |                      | e.g. "10.GB"         |
+---------------------------+----------------------+----------------------+
| contract_name             | varchar              | The name of your     |
|                           |                      | contract or          |
|                           |                      | organisation. In     |
|                           |                      | order to edit this   |
|                           |                      | name please get in   |
|                           |                      | touch with the       |
|                           |                      | dashboard squad,     |
|                           |                      | contact with the     |
|                           |                      | dashboard squad for  |
|                           |                      | this.                |
+---------------------------+----------------------+----------------------+
| sales_chanel              | varchar              | The Sales Channel of |
|                           |                      | the item             |
+---------------------------+----------------------+----------------------+
| fte_ea_name               | varchar              | original column not  |
|                           |                      | existing, we         |
|                           |                      | calculate it with    |
|                           |                      | FTE data             |
+---------------------------+----------------------+----------------------+
| fte_tenant_contract       | varchar              | original column not  |
|                           |                      | existing, we         |
|                           |                      | calculate it with    |
|                           |                      | FTE data             |
+---------------------------+----------------------+----------------------+


Business.product
~~~~~~~~~~~~~~~~

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| product               | varchar              | The ID of the        |
|                       |                      | product used in the  |
|                       |                      | T-Systems billing    |
|                       |                      | system               |
+-----------------------+----------------------+----------------------+
| product_description   | varchar              | The description of   |
|                       |                      | the product          |
+-----------------------+----------------------+----------------------+
| product_category      | String               | The category of the  |
|                       |                      | the product, used in |
|                       |                      | the T-Systems        |
|                       |                      | billing system.      |
|                       |                      |                      |
|                       |                      | There are the        |
|                       |                      | following            |
|                       |                      | categories:          |
|                       |                      |                      |
|                       |                      | -  AI                |
|                       |                      |                      |
|                       |                      | -  Analysis          |
|                       |                      |                      |
|                       |                      | -  Application       |
|                       |                      |                      |
|                       |                      | -  Base              |
|                       |                      |                      |
|                       |                      | -  Compute           |
|                       |                      |                      |
|                       |                      | -  Container         |
|                       |                      |                      |
|                       |                      | -  Database          |
|                       |                      |                      |
|                       |                      | -  Enterprise        |
|                       |                      |    Application       |
|                       |                      |                      |
|                       |                      | -  Licenses          |
|                       |                      |                      |
|                       |                      | -  Management        |
|                       |                      |                      |
|                       |                      | -  Network           |
|                       |                      |                      |
|                       |                      | -  PaaS              |
|                       |                      |                      |
|                       |                      | -  SaaS              |
|                       |                      |                      |
|                       |                      | -  Security          |
|                       |                      |                      |
|                       |                      | -  Service           |
|                       |                      |                      |
|                       |                      | -  Storage           |
|                       |                      |                      |
+-----------------------+----------------------+----------------------+
| producty_family       | String               | The product family   |
|                       |                      | of a service         |
+-----------------------+----------------------+----------------------+


Business.tag
~~~~~~~~~~~~

This table gives you a list of tag keys and tag values, which are
pairs. This table is used in Tagging dashboards to access dashboards
fast. The initial load is slow depending on the amount of data it
needs to query to fill these variables.

+-----------------------+----------------------+----------------------+
| Field name            | Data type            | Description          |
+=======================+======================+======================+
| contract              | Int8                 | Your contract id     |
+-----------------------+----------------------+----------------------+
| reseller_id           | Int8                 | The reseller id is   |
|                       |                      | used in certain      |
|                       |                      | organisation models, |
|                       |                      | you won't need       |
|                       |                      | this in most cases   |
+-----------------------+----------------------+----------------------+
| hash32                | varchar              | Key for internal     |
|                       |                      | purposes             |
+-----------------------+----------------------+----------------------+
| tag_key               | varchar              | The tag keys which   |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+
| tag_value             | varchar              | The tag values which |
|                       |                      | are used in your     |
|                       |                      | infrastructure       |
+-----------------------+----------------------+----------------------+


Business.contract
~~~~~~~~~~~~~~~~~

This table gives you a list of contract-IDs for your
payer/reseller account ID. This table is used in Payer/Reseller
dashboards in order to access dashboards with shower query execution time.
The initial load is slow depending on the amount of data it needs to query 
to fill this variable. Searching for all distinct contract IDs in
business.consumption has the same result as Business.contract, but the
query itself will be resolved much quicker due to smaller datasets.

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
| reseller_id           | Int4                 | The reseller id is   |
|                       |                      | used in certain      |
|                       |                      | organisation models, |
|                       |                      | you won't need       |
|                       |                      | this in most cases   |
+-----------------------+----------------------+----------------------+
| contract              | Int8                 | Your contract id     |
+-----------------------+----------------------+----------------------+
| contract_name         | varchar              | The name of your     |
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


Business.consumption_types
~~~~~~~~~~~~~~~~~~~~~~~~~~

+-------------------------------+----------------------+-----------------------+
| Field name                    | Data type            | Description           |
+===============================+======================+=======================+
| value_type                    | varchar              | This field displays   |
|                               |                      | the type of dataset.  |
|                               |                      | This can be:          |
|                               |                      |                       |
|                               |                      | Cost types:           |
|                               |                      |                       |
|                               |                      | -  K017 & K018        |
|                               |                      |    elastic prices     |
|                               |                      |                       |
|                               |                      | -  D102 advance       |
|                               |                      |    payments           |
|                               |                      |                       |
|                               |                      | -  D536 monthly       |
|                               |                      |    payments           |
|                               |                      |                       |
|                               |                      | -  D104 allowances    |
|                               |                      |                       |
|                               |                      | Discount types:       |
|                               |                      |                       |
|                               |                      | -  R100 applied       |
|                               |                      |    discount           |
|                               |                      |                       |
|                               |                      | R400 enterprise       |
|                               |                      | discount              |
+-------------------------------+----------------------+-----------------------+
| consumption_types_description | varchar              | | Description of      |
|                               |                      |   value type.         |
|                               |                      | | e.g.                |
|                               |                      | | value type = K014   |
|                               |                      |                       |
|                               |                      | Consump               |
|                               |                      | tion_type_description |
|                               |                      | = Usage for PLM Cloud |
|                               |                      | with price            |
+-------------------------------+----------------------+-----------------------+

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
