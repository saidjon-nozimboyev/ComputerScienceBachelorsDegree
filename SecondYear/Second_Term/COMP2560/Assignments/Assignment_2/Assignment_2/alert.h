#ifndef ALERT_H
#define ALERT_H

#define QUEUE_NAME "/comp2560_alerts"
#define LOG_FILE "alerts.bin"
#define DESCRIPTION_SIZE 256
#define ALERT_COUNT 12
#define TERMINATION_ID (-1)

typedef enum { LOW = 1, MEDIUM = 2, HIGH = 3 } Priority;
typedef enum { WEB_SERVER, DATABASE_SERVER, PAYMENT_GATEWAY, EMAIL_SERVER, AUTH_SERVER } TargetService;
typedef enum { BLOCK, ISOLATE, REPORT, AUDIT } Action;

typedef struct {
    int message_id;
    char description[DESCRIPTION_SIZE];
    TargetService target_service;
    Priority priority;
    Action action;
} AlertMessage;

#endif

