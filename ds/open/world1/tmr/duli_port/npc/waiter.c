
#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("�ȩ��A�ȥ�", ({ "waiter"}) );
        set_race("human");
        set("age", 20);
        set("long",@long
�@�Ӭ��G�Q�X�Y���~���A�ȥ͡A�����i���X�۩I�ȫȡC
long
);

        set("merchandise", ([
                __DIR__"obj/manto": 50,
                "/d/obj/food/manto2": 100,
                __DIR__"obj/dumpling": 50,
                __DIR__"obj/bottle": 20,
                  __DIR__"obj/duck-meat": 2,
                  "/d/obj/bag": 10,
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                  "�ȩ��A�ȥͦ��۸߰ݤ@��ȤH���I���s��...\n",
                "�ȩ��A�ȥͯ��۰ݧA�D�G�u�̪񦳤����D�A�i����ťť�ܡH�v\n",
                "�ȩ��A�ȥ�ť�ۤ@��ȤH�������Ȧ毺�ܫ�A�����a���F�_��..\n",
         }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

