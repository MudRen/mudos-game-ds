//�̯S mite.c -Tmr

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name( "�ĳc" , ({ "medication seller" , "seller"}) );
        set_race("human");
        set("title","���`����");
        set("gender", "male");
        set("age", 40 );
        set("long",@long
�@�@�b�A���e���o���ĳc�������u�����A���y�w�g���w�άO���H���k�l�A��
�۹�b�O�୮�����H���������C
long
);

          set("merchandise", ([
                 __DIR__"obj/pellet": 250,
                  __DIR__"obj/pellet": 250,
                  __DIR__"obj/jerk": 250,
          ]));




        set("chat_chance", 5);
        set("chat_msg", ({
                "�ĳc�R�צa�ڤl�s��ۡG�u�o���F��L���į�A������Ӭݬݭ�I�v \n",
                "�ĳc�I�ۨI�����Ľc�A�L�̤����b���ۻy����...\n",
        }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}
