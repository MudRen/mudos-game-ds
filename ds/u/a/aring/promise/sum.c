/*  summon.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <ansi.h>
inherit ITEM;

void create()

{
        set_name(HIC"SUMMON��"NOR, ({"sum machine", "machine"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONGsummon
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_summon","sum");
 
}

int summon(string str)
{
        object ob, me;

        seteuid(getuid(me));
        if(!str) return notify_fail("���O�榡: summon <�ϥΪ�>\n");
        ob = LOGIN_D->find_body(str);
        if(!ob) return notify_fail("�u�W���ϥΪ̤��S���o�ӤH�C\n");

        if(ob&&wizardp(ob) && ob->query("env/����") && wiz_level(me) < wiz_level(ob))
        return notify_fail("�{�b�S�o�ӤH.\n");

        if( wizhood(me) != "(manager)"
        &&      wiz_level(me) <= wiz_level(ob) || wiz_level(me) < 4)
                return notify_fail("���O�榡: summon <�ϥΪ�>\n");

        // moving
        tell_room(environment(ob), "�ѪŤ����X�@���j���"+ob->name() + "��F�_�ӡM�M�ᤣ���F�C\n", ob);
        tell_object(ob,"�@�����A��F�_�ӡM�A���e�@�}�� ....\n");
        ob->move(environment(me));
        tell_object(me, "�A��" + ob->name() + "���A�����e�C\n");
        tell_object(ob,".... ���Ӯɵo�{�O" + me->name() +"��A�˹L�Ӫ��C\n");
        log_file("static/SUMMON",
                sprintf("[%s] %s(%s) summon %s(%s) �� %s\n",
                change_time_scale(time()), me->name(1), geteuid(me), ob->name(1), geteuid(ob),file_name(environment(me)) ) );
        tell_room(environment(ob), ob->name() + "��M�X�{�b�A���e�C\n",({me,ob}));

        // ok ..
        return 1;
}

