#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("�����y", ({ "ha xiao lian","lian"}) );
        set_race("human");
        set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
          set("gender", "male");
          set("title", "�Ƨ���");
        set("age", 20);
        set("long",@long
�����y�O���������Ƨ����A�@�i�y�û��a�۷L���A���G�����S
���~�T�@��A�Y�A���L�d�o�ܭW�y�A�γ\��b���������W�C
long
);

        set("merchandise", ([
            "/d/obj/food/manto": 100,
            "/d/obj/food/manto2": 100,
            "/d/obj/food/dumpling": 100,
            __DIR__"obj/boat_ticket": 50,
            __DIR__"obj/bottle": 50,
            "/d/obj/drug/gin_pill" : 150,
            "/d/obj/drug/hp_pill" : 150,
            "/d/obj/bag" : 30,

        ]));


        set("chat_chance", 5);
        set("chat_msg", ({
                 "�����y���ѥ��F�ӫ����A�z�����d���M���L�b������...\n",
                 "�����y�ﺡ���y�����e�����a�۩I�z...\n",
                 "�����y�����i���X�A�y�W�����N�o�O���@����...\n",
        }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}
