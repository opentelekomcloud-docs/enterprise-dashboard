Configuration and Customization
===============================

The Enterprise Dashboard comes ready to use. However, to customize
access in a role based manner, you can define users with certain
capabilities and configure organizations.


User management
---------------

After booking Enterprise Dashboard Open Telekom Cloud will provide you
an admin account for your organization. An organization contains all
contracts owned by your company. With this admin account, you can set
up (invite) additional users for either your complete organization, a
global view, or certain tenants, a tenant view. Be aware that the
invitation will be valid for 30 days before expiring. The initial
admin account will be created in each organization that represents
your company. You will find more information about the organization
and how they are utilized in Enterprise Dashboard in the next chapter.

The following user groups are available in an organization:

+-----------------------------------+------------------------------------+
| Usergroup name                    | Usergroup permissions              |
+===================================+====================================+
| Admin                             | Can do everything scoped to the    |
|                                   | organization. For example:         |
|                                   |                                    |
|                                   | -  Add and edit data sources.      |
|                                   |                                    |
|                                   | -  Add and edit organization       |
|                                   |    users and teams.                |
|                                   |                                    |
|                                   | -  Create API keys.                |
+-----------------------------------+------------------------------------+
| Editor                            | -  Can create and modify           |
|                                   |    dashboards and alert rules.     |
|                                   |    This can be disabled for        |
|                                   |    selected folders and dashboards.|
|                                   |                                    |
|                                   | -  Cannot create or edit data      |
|                                   |    sources nor invite new users.   |
+-----------------------------------+------------------------------------+
| Viewer                            | -  View any dashboard. This can    |
|                                   |    be disabled on specific         |
|                                   |    folders and dashboards.         |
|                                   |                                    |
|                                   | -  Cannot create or edit           |
|                                   |    dashboards nor data sources.    |
+-----------------------------------+------------------------------------+

You can check your permissions within your user preferences. Click on
your user icon, select “Preferences” and you will find a list of all
organizations you are part of and which permissions you have.


Organization
------------

Enterprise Dashboard is utilizing Grafana’s built in organization
feature, to separate your individual tenants (or in financial terms
your contracts) from each other. Open Telekom Cloud will give you
depending on your Enterprise Dashboard version access to either a
single or multiple/all tenants. Your organization is split into
several Grafana organizations, depending on the number of tenants you
are currently using.

In the following there are some examples:

- If you have one tenant, you should use the medium version and will
  have one Grafana organization, representing the billing data of your
  contract.

- If you have at least two contracts, you should use the large version
  and will have three Grafana organizations. A global organization,
  including the global dashboard, and one organization for each
  individual contract.

- If you have at least three contracts and want to group them
  individually on not per default all in one global dashboard, you
  should use the extra-large version of the dashboard. You will
  receive some global dashboards, depending on your preferences.

This allows you to set up either dedicated user accounts within
Enterprise Dashboard to view just one tenant, or an overall view if
you grant them access to your global dashboard.


Current Limitations
-------------------

In the following you will see a list of current limitations:

- Billing data is updated once per day around 8 am (GMT +2).

- Billing Data is available up to the day before the current date. On
  Tuesday you can see data up until Monday.

- Alerting for queries using Grafana variables (for example $tenant
  from Tenant Switcher, used in Payer based Dashboard) is not
  supported in Grafana.

- VAT or other taxes are not included in Enterprise Dashboard.

-  Enterprise Dashboard cannot be ordered in T-Systems eShop.
   
