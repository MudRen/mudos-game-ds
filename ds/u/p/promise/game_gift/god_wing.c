//�x�����eq 200.10.14 by Promise@DS
#include <armor.h>
#include <ansi.h>
inherit HANDS; 
void create()
{
        set_name(HIW"�ѨϤ��l"NOR,({"the wing of angel","wing","angel","the","of","t","w","o","a"}) );
        set("long",HIW"    �o�O�@�ӳy���_�S����M�A��������������M�W�Y�������~��A
�����F���������Z�A�b�����W�Ƶ۲H�H���ȥզ���~�A���ۧϩ���
�g�z�@���·t�����ءA���X�M�����~�b��M�����H�H�����o�ۡA�n
���H�ɳ��i�ຶ���A���L�׬O�b�h�K�P���Ӷ����U�@���٬O�i�H�M��
���ݨ쥦�������A���L�O�H�_�Ǫ��O�A������o��M�u�����⪺����
�A�ӨS���k�⪺�����C
\n"NOR);
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",2);
         set("material","silver");
         set("unit", "��" );
         set("no_sell",1); 
         set("no_give",1);
         set("no_auc",1);
         set("no_drop",1);         }
        set("armor_prop/armor", 1);
        set("wear_msg","
      [0;1m�[1m�[1m�[1mi[1m�[1mh[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1me[1m�[1mf[1m�[1mg[1m�[1m�[0m "HIG"��"NOR"$N"HIG"�N"HIW"�ѨϤ��l"HIG"���_
[0;1;32m [1m [1m [1m [1;37m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1mi[1m�[1m�[1m�[1mh[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1m�[1;40m�[1m�[1m [0m"HIW"�ѨϤ��l"HIG"�����~�V�ӶV�`��
[0;1;32m [1m [1;37m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1m�[1m�[1mi[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1mc[1m�[1m�[1;40m�[1m�[1;32m [1m [1m [0m"HIG"��A�A���ݲM���ɭ�
[0;1m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1m�[1m�[1m�[1;40m�[1m�[1;47m�[1mh[1m�[1mg[1m�[1me[1m�[1mc[1m�[1mi[1;40m�[1m�[1;32m [1m [1m [1m [1m [0m"HIG"$N������w�g�Ʀ��@�����l
[0;1m�[1m�[1m�[1mi[1m�[1mi[1;47m�[1m�[1;40m�[1m�[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m�[1m�[1;32m [1m [1m [1m [1m [1m [1m [0m"HIG"�ô��o�۩M��Ӥ@�˲H�H������\n"NOR);
     set("unequip_msg",HIG"��$N�N"HIW"�ѨϤ��l"HIG"��U�ɡA���⪺���l�Ƭ��I�I���~���h�A�^�_��즳���ˤl�C\n"NOR);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

