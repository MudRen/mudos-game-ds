#include <ansi.h>
 inherit ROOM;void create()
{
 set("short",HIW"���O�o�b��"NOR);
 set("long",HIW"*   *  *       *   *    *    *      *       *     *
"HIW"*   "HIY"��  "HIW"*     *    *       * *  *   *      *    *    *
"HIW"   *   *"NOR"   "WHT"��    "HIW"*  *             *         "HIG"/|\      "HIW"*
"HIW"   *    "NOR"   "WHT"__o   "HIW"*   *      "NOR""GRN"���@        "HIW"*     "HIG"/||o\   "HIW"*   *
  "HIW"*   ��||_    *      "NOR""GRN"���@  ���@    "HIW"*     "HIG"/|o|||\    "HIW"*
"HIW" *   ���@�@�@     *  "NOR""GRN"��  �@     �@       "HIG"/|||||o|\      "HIW"*
   "HIW"��    �@__�@     "NOR""GRN"��    �@     �@   "HIW"* "GRN"/||o||||||\   "HIW"*
   "YEL"|  "HIR"��  "YEL"| "HIR"E "YEL"|+++|+++++|+++|+++|+++        | |

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
   tell_object(HIW"�o�b�O�ɦ��O�}�l/n"NOR);

 }
}

