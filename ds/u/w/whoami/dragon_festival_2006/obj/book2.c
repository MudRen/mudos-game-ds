
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"²�����ݤȭ���"NOR,({"cookery book","book"}) );
        set("long",@LONG

�x���պ�G�˸��B��÷�B�z�̡B�ը��ơB�ަסB��ۣ�B���J

���n�J��G�˸��B��÷�B�z�̡B�ը��ơB�񨧡B��̡ͦB�n�J


���֤��׺�G�˸��B��÷�B�z�̡B�ը��ơB�񨧡B���סB���֡B�ަ�

�|�t���Q����G�˸��B��÷�B�z�̡B�ը��ơB�����B�ަסB���

�ʪG��l�G�˸��B��÷�B�z�̡B�ը��ơB�V�ʱ��B�֮礯�B�C��

����������G�˸��B��÷�B�z�̡B�ը��ơB���̡B�ڽ����B��ۣ�B���סB�T�_��

���d����G�˸��B��÷�B�z�̡B�ը��ơB��͡B��ۣ�B�ߤl�B�ڽ����B�T�_�̡B����

�s�FĪ�º�G�˸��B��÷�B�z�̡B�ը��ơB�����B�߻T�B�Ǫd�B���T�B�T�_��

LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100);
                set("unit","��"); 
        }
        setup();
}
