
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�ݤȭ��Фj��"NOR,({"cookery book","book"}) );
        set("long",@LONG


�@�@�򥻳W�h

�@�@���`���ը��G�Ц׺�n���N�s�A���ަץΤֳ\����B�տ}�B�s�B�Q�B�ͩ��
�ä��д|���ܽը��~���J�ަצA�]�C

�@�@��l�����ϡG���F�ꤣ�y���o�Ӻ�A����̲����i���F���A�p�G�N���z�|�X�{
���Ͳ{�H�C�Ц׺�p�G�Ϊνަפ��y�Ϻ�B�P��A�קY�i�C�p�G�νG�ަ״N�n�Ϻ�
�A�]���G�׼��F�H��|���Y�A���`���Υķ|�|�J�����A����O����l�����z�C

�@�@�ꪺ�i�N�G�N��l�@�w�n���u�H��~����l�A���n���L�ꭱ�A�ݤ����s�u�_�H
��A�Ω����N3�Ӥp�ɥ��k�Y�i�C�b�N��L�{�����n�K�ͤ��C�n�d�N�c���ꤣ��M��
����l�@�P�N�C�N�n�H��X�����X�C

�@�@�Y�ɥ��}�긭�A�ꭻ�Q��A�J�f�o�Ӥ����A�z�Ӥ��ߡA�в��A���A�����A���O
���W�~�C


�@�@�X�غ�l�����k

�@�@page.1     �x����l
�@�@page.2     ���n�J��
�@�@page.3     ���֤��׺�
�@�@page.4     �ʪG��l
�@�@page.5     ���d����
�@�@page.6     ����������
�@�@page.7     �|�t���Q����
�@�@page.8     �s�FĪ�º�


�@�@(�\Ū�Х�Read ����)
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
