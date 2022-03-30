General Information
===================

Access Enterprise Dashboard
---------------------------

Enterprise Dashboard can be accessed by visiting the following URL:

-  https://enterprise-dashboard.otc-service.com

To enter Enterprise Dashboard you need to enter your credentials. Your email and password are required. You will receive an invitation for Enterprise Dashboard, once the order is confirmed and processed. With this invitation, you can set the password of your user account.

Your email and password are case-sensitive. Please check upper and lower cases before clicking Log In.

**\*Note\*** Enterprise Dashboard is offered via­­­­­­­ Direct sales only. Please contact either your contractual partner to set up your access or contact Request-OpenTelekomCloud@telekom.de

Product Versions
----------------

Enterprise Dashboard is available in 3 versions.

+-------------------------------------------+------------------+-------------------+------------------+--------------+
| Product versions                          | API access       | Dashboard Self    | Multi-Tenant     | O            |
|                                           |                  | Service           |                  | rganizations |
|                                           |                  |                   |                  | Management   |
+===========================================+==================+===================+==================+==============+
| Enterprise Dashboard Medium               | ✓                | ✓                 |                  |              |
+-------------------------------------------+------------------+-------------------+------------------+--------------+
| Enterprise Dashboard Large                | ✓                | ✓                 | ✓                |              |
+-------------------------------------------+------------------+-------------------+------------------+--------------+
| Enterprise Dashboard Extra Large          | ✓                | ✓                 | ✓                | ✓            |
+-------------------------------------------+------------------+-------------------+------------------+--------------+

The product feature “\ **API access**\ ” gives you access to all API calls described in chapter “API”.

The product feature “\ **Dashboard Self Service**\ ” gives you the option to create “Admin” or “Editor” users, which are allowed to create dashboards, widgets, alerts, or users by themselves. Some examples are described in the Chapter “How to”.

The product feature “\ **Multi-Tenant**\ ” gives you access to a global dashboard, which aggregates all spendings across several tenants. This allows you to manage your business on a bigger scale.

.. image:: ./media/image03.png
   :width: 6.19444in
   :height: 3.01797in

In a scenario like the above, it gets very hard for User A to compare data from multiple tenants. Each of his tenants has only access to the data of the own tenant. To compare data he needs a global dashboard, which allows him to access and compare data of all tenants in one organization. Also from a financial perspective, it’s recommended to consume Enterprise Dashboard Large instead of multiple Enterprise Dashboard Medium.

The product feature “\ **Organizations Management**\ ” helps you to easily manage access to your dashboards and data. It allows you to split your payer account (see `chapter 2.4 <#Organizations>`__) into smaller parts with separate global dashboards. This allows you to move certain tenants into a new completely separated organization with new users, user groups, and dashboards.

.. image:: ./media/image04.png
   :width: 6.69347in
   :height: 2.32639in

In a scenario like above, where User B is not allowed to access certain tenants, you can separate those tenants and give User B access to that organization and therefore access to the global dashboard.

User management
---------------

After booking Enterprise Dashboard Open Telekom Cloud will provide you an admin account for your organization. An organization contains all contracts owned by your company. With this admin account, you can set up (invite) additional users for either your complete organization, a global view, or certain tenants, a tenant view. Be aware that the invitation will be valid for 30 days before expiring. The initial admin account will be created in each organization that represents your company. You will find more information about the organization and how they are utilized in Enterprise Dashboard in the next chapter.

The following user groups are available in an organization:

+----------------------------------------------------------+-----------------------------------------------------------+
| Usergroup name                                           | Usergroup permissions                                     |
+==========================================================+===========================================================+
| Admin                                                    | Can do everything scoped to the organization. For         |
|                                                          | example:                                                  |
|                                                          |                                                           |
|                                                          | -  Add & Edit data sources.                               |
|                                                          |                                                           |
|                                                          | -  Add & Edit organization users & teams.                 |
|                                                          |                                                           |
|                                                          | -  Create API Keys                                        |
+----------------------------------------------------------+-----------------------------------------------------------+
| Editor                                                   | -  Can create and modify dashboards & alert rules. This   |
|                                                          |    can be disabled on specific folders and dashboards.    |
|                                                          |                                                           |
|                                                          | -  Cannot create or edit data sources nor invite new      |
|                                                          |    users.                                                 |
+----------------------------------------------------------+-----------------------------------------------------------+
| Viewer                                                   | -  View any dashboard. This can be disabled on specific   |
|                                                          |    folders and dashboards.                                |
|                                                          |                                                           |
|                                                          | -  Cannot create or edit dashboards nor data sources.     |
+----------------------------------------------------------+-----------------------------------------------------------+

You can check your permissions within your user preferences. Click on your user icon, select “Preferences” and you will find a list of all organizations you are part of and which permissions you have.

Organization
------------

Enterprise Dashboard is utilizing Grafana’s built in organization feature, to separate your individual tenants (or in financial terms your contracts) from each other. Open Telekom Cloud will give you depending on your Enterprise Dashboard version access to either a single or multiple/all tenants. Your organization is split into several Grafana organizations, depending on the number of tenants you are currently using.

In the following there are some examples:

-  If you have one tenant, you should use the medium version and will have one Grafana organization, representing the billing data of your contract

-  If you have at least two contracts, you should use the large version and will have three Grafana organizations. A global organization, including the global dashboard, and one organization for each individual contract

-  If you have at least three contracts and want to group them individually on not per default all in one global dashboard, you should use the extra-large version of the dashboard. You will receive some global dashboards, depending on your preferences.

This allows you to set up either dedicated user accounts within Enterprise Dashboard to view just one tenant, or an overall view if you grant them access to your global dashboard.

Current Limitations
-------------------

In the following you will see a list of current limitations:

-  Billing data is updated once per day around 8 am (GMT +2)

-  Billing Data is available up to the day before the current date. On Tuesday you can see data up until Monday

-  Alerting for queries using Grafana variables (for example $tenant from Tenant Switcher, used in Payer based Dashboard) is not supported in Grafana

-  VAT or other taxes are not included in Enterprise Dashboard

-  Enterprise Dashboard cannot be ordered in T-Systems eShop
