inherit ITEM;

void create()
{
        set_name("�}�l���۹�", ({ "breakage statue", "statue" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
�o�O�@�y�}�l���۹��A�̵}�٥i�H�{���X�O�����ﮦ���۹��C
�۹��Y�W���ۤ@��s�Ϩ��A�y�W���ۤs���G�A���ۤH�����W�b��
�A�U���o�O����s�ϡC�A�٪`�N��۹��]�����~�����j�B���A�y
�W���۲�(look eye)�w�g�n�n���Y�F�C
LONG
);

                set("value", 1);
                set("no_get",1);
                  set("no_sac",1);
        }
}

void init() {
        add_action("do_look","look");
        add_action("do_install","install");
}

int do_look(string arg) {
          if( arg != "�۲�" && arg != "eye") return 0;
        tell_object(this_player(), "�A�ݥ۲����M�}�l�����Y���A�����G�٥i�H��(install)���^�h�C\n" );
        return 1;
}

int do_install(string arg) {
        if( arg != "�۲�" && arg != "eye" ) return notify_fail("�A�Q�n�ˤ���F��H\n");
        if( this_player()->is_busy()) return notify_fail("�A�����ۡA�S���Ű��o��ơC\n");
        message_vision("$N�n�߱N�}�l�۹��W���۲��ߥ��A�ˤF�^�h�C\n", this_player() );
        this_player()->set_temp("enter_goat_maze",1);   // �i�H�i�J�Ϩk���g�c
        this_player()->start_busy(1);
        return 1;
}

