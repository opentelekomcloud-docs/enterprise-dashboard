import requests
import json
import logging

# Configure logging
logger = logging.getLogger()
logging.basicConfig(level=logging.INFO)

# API endpoint for daily consumption
API_URL = "https://api-enterprise-dashboard.otc-service.com/v2/daily/consumption/"
TOKEN = "<YOUR_TOKEN_HERE>"  # Service account or API token

# Set request headers
headers = {
    "Content-Type": "application/x-ndjson",
    "Authorization": f"Bearer {TOKEN}",
}

# Make GET request with query parameters
try:
    response = requests.get(
        API_URL,
        headers=headers,
        params={
            "date": "2025-02-02",
            "consumption_type": "EL",
            "week": 5,
        },
        timeout=60,
    )

    if response.status_code != 200:
        logger.error("Failed to fetch data: %s", response.text)
    else:
        # Stream and decode the JSON lines
        for data_row in response.iter_lines(decode_unicode=True):
            if data_row:
                data = json.loads(data_row)
                logger.info("Received data: %s", data)

except requests.exceptions.RequestException as e:
    logger.exception("Request failed: %s", str(e))
