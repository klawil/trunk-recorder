#ifndef PARSE_H
#define PARSE_H
#include <iostream>
#include <vector>

enum MessageType {
  GRANT = 0,
  STATUS = 1,
  UPDATE = 2,
  CONTROL_CHANNEL = 3,
  REGISTRATION = 4,
  DEREGISTRATION = 5,
  AFFILIATION = 6,
  SYSID = 7,
  ACKNOWLEDGE = 8,
  LOCATION = 9,
  PATCH_ADD = 10,
  PATCH_DELETE = 11,
  DATA_GRANT = 12,
  UU_ANS_REQ = 13,
  UU_V_GRANT = 14,
  UU_V_UPDATE = 15,
  ADJACENT_STATUS = 98,
  UNKNOWN = 99
};

struct PatchData {
  unsigned long sg;
  unsigned long ga1;
  unsigned long ga2;
  unsigned long ga3;
};

struct AdjacentStatus {
  unsigned long lra;
  unsigned long sys_id;
  unsigned long rfss;
  unsigned long site;
  unsigned long freq_band;
  unsigned long ch_num;
  unsigned long freq;
  bool conv_ch;
  bool site_failed;
  bool valid_info;
  bool active_conn;
  bool composite_ctrl;
  bool no_service_req;
  bool backup_ctrl;
  bool supports_data;
  bool supports_voice;
  bool supports_registration;
  bool supports_authentication;
};

struct TrunkMessage {
  MessageType message_type;
  std::string meta;
  double freq;
  long talkgroup;
  bool encrypted;
  bool emergency;
  bool duplex;
  bool mode;
  int priority;
  int tdma_slot;
  bool phase2_tdma;
  long source;
  int sys_num;
  unsigned long sys_id;
  int sys_rfss;
  int sys_site_id;
  unsigned long nac;
  unsigned long wacn;
  PatchData patch_data;
  unsigned long opcode;
  AdjacentStatus adjacent_status;
};

class TrunkParser {
  std::vector<TrunkMessage> parse_message(std::string s);
};
#endif
