// Room: /u/t/tmr/area/hotel.c

#include <ansi2.h>
inherit ROOM;
string look_list(object me);
void create()
{
        set("short", "�¤Ѽ�");
        set("long", @LONG
�@���]�u�¤Ѵ�v�ӿ��_���ȴ̡A�¤ѼӪF�_�����b���a�Y�����
�A�G�����ȴ̤j���L���C���w��A�`�`�󦹦�J�B�ο��C���e�����^���
��A�@�Ӥj���O���򻨤h�άO�M�`�ʩm�b���ܰs�Y�סA�R�ժ��n���A���p
�G���۩۩I�ȤH�A�J�������ȤH��O���椣���C����j�ۦ�î�Ǩ������
�I�B�L�J�������n���A�ݨӬO�o�̪��p�ФF�C��W�K�F�i�I�αƦ�] ---
(rich_list)�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inn_2f",
  "east" : __DIR__"street4",
  "down" : "/open/world1/wilfred/newbie/eq_bank",
  "newbie" : __DIR__"school/school1", 
  "bug" : "/open/world2/anfernee/start/bug",    
 //"west" : "/u/a/alickyuen/open/moon/en1", 
]));
        set("objects", ([ /* sizeof() == 1 */
//  "/open/world1/mirror.c": 1,
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/basic_master" : 1,  

//  __DIR__"npc/eq-man":1, 
// "/open/world1/promise/xmas-lady" : 1,
]));
        set("item_desc",([
     "rich_list": (: look_list :),
        ]));
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);

        setup();
     call_other("/obj/board/tmr_hotel_b", "???");
}

string look_list(object me)
{
        return RECORD_D->query_past_money_rec();
}
int valid_leave(object me, string dir)
{
        if( dir=="newbie" || dir=="bug" && !userp(me))
        return notify_fail("���̥u�����a�~��i�h�C\n");    
        if( dir!="newbie" )return ::valid_leave(me, dir);
        else if( me->query("not_newbie") )
                return notify_fail("�A�w���O�s��F�I\n");

        return ::valid_leave(me, dir);
}

void update_player() {

        object me = this_player();
        // delete unused skills
        me->delete_skill("sevenstar-sword");
        me->delete_skill("lan_pu");

        // �Nmoney-dart�令nine-waterfall
        // ��s quest
        me->delSolved("/open/quest/mouse_q1.c");
        me->delSolved("/open/quest/mouse_q2.c");
        me->delSolved("/open/quest/mouse_q3.c");
        me->delToDo("/open/quest/mouse_q1.c");
        me->delToDo("/open/quest/mouse_q2.c");
        me->delToDo("/open/quest/mouse_q3.c");
        if( me->query_skill("money-dart") > 0) {
                me->set_skill("nine-waterfall", me->query_skill("money-dart") );
                me->delete_skill("money-dart");
        }

        // �Nsorsin_force�令 indicate-knack
        if( me->query_skill("sorsin_force") > 0) {
                me->set_skill("indicate-knack", me->query_skill("sorsin_force") );
                me->delete_skill("sorsin_force");
        }

        // ��s�ѽ��ݩ�
        if( me->query("class1") == "�ѱ���") {
                me->set("guild_gifts", ({2,7,8,3 }) );
        }
        if( me->query("class1") == "�H����") {
                me->set("guild_gifts", ({0,5,9,6}) );
        }
        if( me->query("class1") == "�֫ӭx") {
                me->set("guild_gifts", ({8,8,0,4}) );
        }
        if( me->query("class1") == "�ⶳ�x") {
                   me->set("guild_gifts", ({8,4,8,0}) );
        }
        if( me->query("class1") == "���Z��") {
                me->set("guild_gifts", ({2,4,9,5}) );
        }
        if( me->query("class1") == "������") {
                me->set("guild_gifts", ({4,6,3,7}) );
        }
          if( me->query("class1") == "�����v") {
                  me->set("guild_gifts", ({7,4,7,2}) );
          }
         if( me->query("class1") == "�e����") {
                 me->set("guild_gifts", ({5,7,0,8}) );
          }

         if( me->query("class1") == "thief") {
                 me->set("guild_gifts", ({3,7,0,10}) );
          }



}

void init()
{
         if( !wizardp(this_player()) && this_player()->query("class1") != "���Z��" && this_player()->query_spell("god-fire") ) 
         {
                 write(HIR"\n\n\t�A�Y���@�}�V�P�A��ѤF �诫��-���u��(god-fire) �k�N�C\n\n"NOR);
                 log_file("del_spell", "delete " + this_player()->query("name") + "(" + getuid(this_player()) + ") god-fire spell.."+ this_player()->query_spell("god-fire") +"\n");
                 this_player()->delete_spell("god-fire");
         }
    update_player(); // add by tmr 2007/01/04
}

