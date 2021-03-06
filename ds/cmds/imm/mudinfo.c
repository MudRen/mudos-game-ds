// /mudinfo.c

#include <mudlib.h>
#include <command.h>

inherit F_CLEAN_UP;

#define SCALE   (1.0/10.0)
#define STATUS  "系統函數庫改寫中"

string memory_expression(int m)
{
    float mem;

    mem = m;
    if( mem<1024 ) return m + "";
    if( mem<1024*1024 )
	return sprintf("%.2f K", (float)mem / 1024);
    return sprintf("%.3f M", (float)mem / (1024*1024));
}

string query_now_time()
{
    int t, d, h, m, s;
    string time;

    t = uptime();
    s = t % 60;             t /= 60;
    m = t % 60;             t /= 60;
    h = t % 24;             t /= 24;
    d = t;

    if(d) time = chinese_number(d) + "天";
    else time = "";

    if(h) time += chinese_number(h) + "小時";
    if(m) time += chinese_number(m) + "分";
    time += chinese_number(s) + "秒";

    return sprintf(""+time);
}

int main( object me, string arg) 
{
    float value;
    mapping r;
    string msg;

    r = rusage();
    value = SCALE * (r["utime"] + r["stime"]) / uptime();

    msg = sprintf( @LONG
        .__________ 系 統 資 訊 __________.
──────────────────────────
 Mud 的識別名稱﹕  %s.
 Mud 的網路名字﹕  %s.
 工作站作業平台﹕  %s.
 界面系統的版本﹕  %s driver 
 系統函數庫版本﹕  %s
 CPU 使用百分比﹕  %f %% 被這個 Mud 使用中.
 CPU 的負擔狀況﹕  %s
 共使用的記憶體﹕  %s bytes.
 線上使用者總數﹕  %d  個人在線上.
 載入的物件總數﹕  %d 個物件.
 虛擬物件的總數﹕  %d 個虛擬物件.
 房間物件的總數﹕  %d 個房間被載入.
 連續執行的時間﹕  %s
 系統時間﹕        %s
 Mud 現在的狀態﹕  %s
LONG,
      MUD_NAME,
      INTERMUD_MUD_NAME,
      __ARCH__,
      __VERSION__,
      MUDLIB_VERSION,
      value,
      query_load_average(),
      memory_expression(memory_info()),
      sizeof( users() ),
      sizeof( objects() ),
      sizeof( objects( (: virtualp :) )),
      sizeof( objects( (: $1->is_room() :))),
      query_now_time(),
      ctime( time() ),
      STATUS
    );
    tell_object( me, msg );

    return 1;
}

int help() {
    write(@HELP
指令格式﹕mudinfo

這個指令將會顯示有關這個 Mud 的一些系統資訊。

HELP
    );
    return 1;
}
