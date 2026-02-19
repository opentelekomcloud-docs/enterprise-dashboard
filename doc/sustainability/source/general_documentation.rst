About the Sustainability Dashboard Version 1.0
==============================================

The Sustainability Dashboard provides service-level transparency on estimated power
consumption and associated greenhouse gas emissions for workloads running on
T Cloud Public. Its primary objective is to empower customers to better understand, assess,
and manage the environmental footprint of their cloud usage using a consistent, documented,
and standards-aligned methodology.
The dashboard is based on a cloud service catalog modelling approach, meaning that
sustainability metrics are calculated per cloud service (e.g. compute, storage, network),
rather than using aggregated or purely financial proxies. This allows for improved accuracy,
comparability across services, and meaningful sustainability insights at workload level.

Power consumption estimation methodology
========================================

Modelling approach
------------------

Power consumption is estimated using architecture-aware service models, derived from:
    - Technical analysis of the underlying cloud infrastructure.
    - Average power consumption measurements collected from thousands of physical systems
      hosting active workloads (including compute servers, storage nodes, and network equipment).
    - Platform-level resource allocation logic reflecting how services consume shared
      infrastructure.

Power consumption estimation background
---------------------------------------

For most cloud services shown in this dashboard, power consumption is estimated by linking each
service to the underlying infrastructure it uses. Allocation is based on technical drivers such
as vCPUs, allocated memory, storage capacity, and service-specific scaling behavior.
When infrastructure components are shared across services or tenants, consumption is distributed
proportionally according to resource size. This ensures fair allocation, for example, a small
virtual machine is assigned a smaller share of host power than a large or heavily utilized
instance, reflecting typical usage patterns and architectural design.

Scope and inclusions
--------------------

These components are included in the power consumption estimates:
    - IT equipment power consumption (compute, storage, network),
    - Associated platform overheads required to operate the services,
    - A proportionate share of shared infrastructure required to deliver the service.

These components are excluded from the power consumption estimation: 
    - End-user devices,
    - Customer on-premises infrastructure,
    - Non-IT building-related energy consumption unless directly attributable to service operation.

General assumptions
-------------------
    - Power consumption values represent average operational behavior, not instantaneous measurements.
    - Models prioritize completeness and consistency over precision at individual resource level.
    - Where a direct measurement is not available, conservative assumptions are applied to avoid
      underestimation.
    - Overhead non-IT data center power consumption (e.g. lighting, cooling, security systems) is
      incorporated into the power consumption of each service by applying the Power
      Usage Effectiveness (PUE) factor of the hosting region, proportionally allocating non-IT
      energy overheads to IT service consumption.
    - Methodologies are applied uniformly across services to ensure comparability.

Emissions estimation methodology
================================

Scope and standard
------------------

Greenhouse gas emissions are calculated in accordance with the GHG Protocol, focusing on:
    - Scope 1 (direct emissions, where applicable),
    - Scope 2 (market-based) emissions associated with electricity consumption.

The dashboard reports emissions resulting from the estimated power consumption of cloud services, 
using market-based emission factors.

Electricity emission factors
----------------------------

Emissions are calculated by applying electricity emission factors to the estimated power consumption:
    - mission factors are region-specific, reflecting the electricity sourcing context of each
      data center region. Since DTAG purchases all its energy from clean renewable sources, this
      mainly refers to the contribution of on-site emergency power generation (e.g. diesel generators),
      based on their usage patterns, fuel type, and share of total electricity supplied during
      the reporting period.
    - Market-based emission factors are applied in accordance with the GHG Protocol, considering
      contractual instruments such as Power Purchase Agreements (PPAs) and Guarantees of Origin
      (GoOs), consistent with DTAG´s commitment to 100 % renewable electricity procurement.
    - Emission factors are expressed in kg CO₂e per kWh. For display purposes, values are
      automatically scaled to µg, mg, g, or kg of CO₂e by the dashboard, depending on the
      magnitude of emissions for the selected reporting period.

Methodological consistency and evolution
========================================

This dashboard represents an evolution from earlier, more aggregated estimation approaches
by T Cloud Public. Previous methodologies intentionally applied highly conservative,
cost-based allocation to ensure no energy consumption was excluded where technical attribution was limited.
The current modelling strategy aims to provide improved granularity and accuracy by replacing
financial proxies with technical allocation models, without narrowing reporting boundaries.
Differences between historical and current values reflect this methodological improvement rather than
changes in infrastructure efficiency or reporting scope. All assumptions, boundaries, and calculation
approaches are documented to ensure transparency and reproducibility.

Treatment of highly abstract services
=====================================

For a limited subset of highly abstract services, like key management operations, or traffic analysis
functions,  direct mapping to specific infrastructure components is not technically meaningful due
to their highly distributed and ephemeral execution characteristics. For these services, power consumption
is estimated using a derived €/kWh conversion factor, extrapolated from the average power consumption
coefficients of services that follow the full service-to-infrastructure mapping described in the modelling
section. These represent only a small subset of services (less than 5%). This approach is aligned with
established sustainability accounting frameworks, including:

     - The Greenhouse Gas Protocol, which allows the use of secondary data and estimation methods where
       primary data is unavailable, provided transparency and consistency are maintained.
     - The International Organization for Standardization standard ISO 14067, which permits the use of
       proxy data and allocation models when justified and documented.
     - Guidance from the Green Software Foundation, which recognizes model-based estimation in distributed
       computing environments where direct metering at service level is technically constrained.

In practice, environmental reporting commonly accepts a limited proportion of modelled data to ensure
completeness, auditability, and methodological consistency.

Intended use and interpretation
===============================

The Sustainability Dashboard is designed to:
    - Support sustainability reporting and internal environmental analysis.
    - Enable comparison between workloads, services, and regions.
    - Identify optimization opportunities and track improvements over time.
    - Improve transparency on the environmental impact of cloud usage.

The values provided are model-based estimates derived from validated allocation methods. They
represent a consistent and robust approximation of both relative and total environmental impact within
the defined system boundaries. 

Because cloud environments are shared and distributed, the data should be interpreted as environmental
indicators rather than direct meter readings from individual resources. The strength of the methodology
lies in its consistency over time, enabling meaningful comparison, optimization, and reporting.
