#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", HIY"�ӫҤj�U"NOR);
        set("long", @LONG
�o�O�H����̪��ӫҤj�U�A�U���D�`�e���C�A�`�N�U�e
�����j��A��W���G���ӫҪ��L��(document)�C
LONG
);
        set("exits",([
        "south" : __DIR__"map_8_7",
        ]));
        set("call_emperor",1);
        set("item_desc", ([ /* sizeof() == 1 */
  "document" : "�@���W�Y�g�۬��L�X�����L�ѡA�ݭn�[�\\�ҦL(affix document)�~��ͮġC\n",
]));

    set("objects", ([
        __DIR__"npc/orc_envoy" : 2,
    ]));

        set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
}

void init() {
        add_action("do_affix","affix");
}

int do_affix(string arg) {
        object ob, stamp;

        if(!arg || arg != "document" )
                return notify_fail("�A�Q�n������H\n");

        stamp = present("_EMPEROR_STAMP_", this_player());
        if( !objectp(stamp) )
                return notify_fail("�A�S������i�H�\\�L�����~�C\n");


        message_vision(CYN"$N"CYN"���_�H���ҦL�A�զۦb�L�ѤW�\\�F�Ӥj�L�I�I\n"NOR, this_player());

        ob = find_living("_CRUSH_BONE_EMPEROR_");        
        if(objectp(ob) && !objectp(environment(ob))) 
                destruct(ob);

        if( objectp(ob) )
                return 1;
        
        ob = new(__DIR__"npc/orc_herald.c");
        ob->move(this_object());
        ob = new(__DIR__"npc/orc_herald.c");
        ob->move(this_object());
        ob = new(__DIR__"npc/orc_emperor.c");
        ob->move(this_object());

     message("world:world1:vision",
           HIR"\n\t"+ob->name()+HIR"�j�q�G�u�����ðʧڪ��ҦL�I�I�A�o�Ӥj�f���D���{�I�I"+this_player()->name(1) + "(" + this_player()->query("id") +") �����a�I�I�v\n\n" NOR
        ,users() );
        
        destruct(stamp);        
        return 1;
}

