/*	File : "..\dodgeman.c" 
	Author : Alickyuen@ds
	Last modify : 2002�~5��14��	*/

#include <ansi2.h>

inherit NPC;

void create()
{
        set_name(HIY"���Y���u�ɤH"NOR, ({ "5 head 6 arms copper man", "man" }) );
        set("level", 35);
	set("long", @long
�@�L���ذ��������ɤH�A�~�άO���`��DOpek���ˤl½�ҦӦ��A����
���׽u���z�{�A�ݫe���s����A�I���٨観�Ѧa�|���лx�C�ɤH����
�Ӯ��Y�W���]�W�p�p���ֵ��A�j�j�a���C�F�����ˮ`�O�C�ɤH���{��
�B���@����աA���䪺�ȱ��W�g��"�ϥνЧ�ʪT�j��"�B
Please "pay money"�C
long);
	setup();
}

void init()
{
        add_action("do_enter", "pay");
}

int do_enter(string arg)
{
        object me, obj;

        me = this_player();
        obj = this_object();

        if( obj->query("attacking") ) 
                return notify_fail("�{�b�w�g�b�������A�е�������A�J�L���C\n");

        if( !arg || arg != "money" )
                return notify_fail("�C�����Q200 coin�A�ϥήɶ���������C\n");

	me->add("bank/past", -100);
	me->force_me("deposit 100");

        obj->set("attacking", 1);
        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 2);

        obj->delete("attacking");

        return 1;
}
