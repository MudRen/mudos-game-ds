#include <ansi2.h>
inherit ITEM;

#define BOSS "/open/world1/tmr/blood_field2/npc/nightbane.c"
#define TREEBREAD "/open/world1/tmr/blood_field2/npc/ents3.c"

void create()
{
    set_name(HBK"�]�ׯQ��"NOR, ({"nightbane dark-stone", "dark-stone", "stone", "_NIGHTBANE_STONE_"}));
    if( !clonep() ) {
        set("long", @LONG
�o�O�@���º��������Y�A���ۤ�W�N���Ѥ��Ԥ��P�C
LONG
                );
        set("value", 10);
        set("unit", "��");
        set("weight", 10);
        set("value",10);
        } else
                   set_default_object(__FILE__);
    setup();
}

void init()
{
  add_action("do_crumb","crumb");
}

int do_crumb(string arg) {
        
        object ob;
        if(!arg || arg != "stone")
                return notify_fail("�A�Q�n���H����H\n");
        
        if( environment(this_player())->query("short") != "���s����" )
                return notify_fail("�A�b�o�̦��G���H�]�ׯQ�ۡC\n" );

        ob = find_living("_NIGHTBANE_");        
        if(objectp(ob) && !objectp(environment(ob))) 
                destruct(ob);

        if(objectp(ob) )
                return notify_fail("�]�פw�g�b����X�S�F�C�A�L�k���H�]�ׯQ�ۡC\n" );
        
        message_vision(HBK"$N"HBK"�ΤO���H�]�ׯQ�ۡA���_�X�j�q���@�@�·ϡA�R���b��ӪŶ��I�I\n"NOR, this_player());
        
        ob = new(TREEBREAD);
        ob->move(environment(this_player()));
        ob = new(TREEBREAD);
        ob->move(environment(this_player()));
        ob = new(BOSS);
        ob->move(environment(this_player()));

     message("world:world1:vision",
           HIR"\n\t"+ob->name()+HIG"�o�X�`�I����q�G�u�L�����Z�H "+this_player()->name(1) + "(" + this_player()->query("id") +") �I�I�ǩR�ӧa�I�I�I�v\n\n" NOR
        ,users() );
        
        destruct(this_object());        
        return 1;
}


