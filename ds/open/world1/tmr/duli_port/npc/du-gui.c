#include <npc.h>
inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("���p�t", ({ "du-gui","gui" }) );
        set("long",@long
���p�t�O�@�Ӧ~�����p���ĵ��A���W�I�ۤ@�Ӥj�c�l�A���u�۽X�Y�s
���C
long
);
        set_race("human");
        set("age", 9);
        set_attr("str",5);
        set_attr("cps",2);
        set("chat_chance", 5);
        set("chat_msg", ({
                "���p�t�j�n�۹D�G�u�U����͡B�p�j�A���H���q����@�i�u�n�K��200�٥��@..�v \n",
                "���p�t�G�p�������b�������H�s�Q�d���o�B����....\n",
                "���p�t�ݵۧA�ݹD�G�u�A�n�R��ܡH�H�v\n",
        }));
        set("merchandise", ([
                __DIR__"obj/boat_ticket":30,
                  "/d/batogiya_dtl/npc/obj/boat_ticket2" : 30,
        ]));

        set("title","��c���");
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


