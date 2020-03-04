#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name(HBK"�����۹�" NOR ,({"pan's statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
    �Ϸ�A�ϻL�A�Ͽ�A�����۹��ٯd�s�ۤӦh�~���ݯd�A͢������
���G�|�����o�H���ί����{�ҡC͢�Q��v�b���ΤH����줧�~�A͢�S��
�K�a�b���ΤH����t�A�a���~���g���B����B�����B�x�઺���ġA�ݮ�
�ۡA�չϫI�����p���ΤH�����C�A�`�N��o�y�۹��W�ʤF�@����(eye)
�A�y�W�N�o�˯d�۳o�B�ʶ��C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�L");
                set("no_get",1);
                set("no_sac",1);
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_install","install");
}

int do_install(string arg)
{
        object me, eye;
        me = this_player();
        if(!arg || arg!="eye") return notify_fail("�A�Q�n�w�ˤ���F��H\n");
		// ��������
        if(!objectp(eye=present("_PAN_EYE_",me) ) )
                return notify_fail("�A���W�S���o�ӪF��C\n");
		if( query_temp("call") || query_pan() )
				return notify_fail("�A�o�{�۹��W���Ⱖ�۲����n�L�ʡA�A���ݭn�A�w�˳o�ӥ۲��F�C\n");

        destruct(eye);
        message_vision("$N�Ӥߦa�N���������˦^�۹��y�W�C\n",me);
        message_vision( CYN "�����۹����Ⲵ���M�F���a��F��...\n"NOR, me);
		set_temp("call",1);
        call_out("open_war",3 ,me);
        return 1;
}

void open_war(object me)
{
        object g;

		set_temp("call", 0);

        // �����ﮦ
        g = new( __DIR__ + "pan.c" );
        g->move(TMR_PAST + "goat_maze/stairway4" );

		if( !objectp(g) ) return;

        message("world:world1:vision",
HIW"\n\n    "+me->query("name") +HIW "Ĳ�ʤF�d�s�W�d�~���j�ѫʦL�A�@�D���ժ�������g�쯫�����a���s��...\n\n"
HIY"        ��v�b�m���B�o�V�B�O�L�B��A����"HIG"�����ﮦ"HIY"�A�a�ۨ�󪺦Ϫ��̨��A�^��F�Ϩk���g�c�C\n\n" NOR
,users() );
}

int query_pan()
{
        object pan;

		// �P�_�O�_�w�g�s�X����
        while( objectp(pan=find_living("bariour_pan")) )
        {
			// ��쪪��
			if( environment(pan) ) break;
			
			destruct(pan);
            pan = 0;
        }

        if( objectp(pan) )
			return 1;

		return 0;
}
