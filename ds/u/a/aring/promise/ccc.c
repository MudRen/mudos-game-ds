#include <ansi.h>
 inherit ROOM;void create()
{
 set("short",HIW"收費發呆室"NOR);
 set("long",HIW"*   *  *       *   *    *    *      *       *     *
"HIW"*   "HIY"★  "HIW"*     *    *       * *  *   *      *    *    *
"HIW"   *   *"NOR"   "WHT"ｏ    "HIW"*  *             *         "HIG"/|\      "HIW"*
"HIW"   *    "NOR"   "WHT"__o   "HIW"*   *      "NOR""GRN"／＼        "HIW"*     "HIG"/||o\   "HIW"*   *
  "HIW"*   ＿||_    *      "NOR""GRN"／＼  ／＼    "HIW"*     "HIG"/|o|||\    "HIW"*
"HIW" *   ／＼　＼     *  "NOR""GRN"／  ＼     ＼       "HIG"/|||||o|\      "HIW"*
   "HIW"／    ＼__＼     "NOR""GRN"／    ＼     ＼   "HIW"* "GRN"/||o||||||\   "HIW"*
   "YEL"|  "HIR"田  "YEL"| "HIR"E "YEL"|+++|+++++|+++|+++|+++        | |

"NOR);
 set("light",1);
 set("hide_exits", ([ /* sizeof() == 2 */
    "js"   : __DIR__"/u/j/jangshow/workroom", 
]));
 set("no_clean_up", 1);
 setup();
 //call_other("/u/i/idle/board", "???");
}
void init()
{
 add_action("do_idle","idle");
}

int do_idle(string arg)
{
 if(arg=="")
 {
   tell_object(HIW"發呆記時收費開始/n"NOR);

 }
}

