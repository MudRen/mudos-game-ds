// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�ѿO����",({"wish_lamp doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�ѿO�S�٬��թ��O�A�۶Ǭ��T��Ѹ��G���o���A�]�Q���{������y���l��
�A�_��O���F�ǻ��T�����ΡA���ثe�q�`�h�Q���`�y��ֳ\�@(wish)���u��C
�ӳo�ӬO�@�Ӵ��ۤѿO���v�����A�D�`���߮�v�v�C
LONG
                );
                set("undead_msg",HIY"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�_�X�벴�����~�A�����F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }


