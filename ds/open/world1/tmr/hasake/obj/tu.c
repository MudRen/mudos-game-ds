#include <ansi.h>

inherit ITEM;

mapping *long_desc = ({
 ([ "name":HIW"������"NOR,
    "long": "\n
                    �m�����ϡn
���ϼg�F�Y�����x�ഺ�A���N��w�A�p���w�O�K�C�e�s�a��W�Y�A
�g������L���A�j�e�����ؤ��S�ߪ̡C�쬰�����X���áA�D�����_
�����U�e�����ϡA���~�~�l�M�Y�P���u�񡨡A��H�q���C�Ҥ���s
�����A���D���~�~�Ѩ������A�����G�������ϡA�Z������ø�C���G
���Ϲꬰ�Z�����@�C\n",]),

([ "name":YEL"��ˤT����"NOR,
   "long": "\n
                   �m��ˤT���ϡn 
��ˤT���G�ơA�f�s�O���G�����k�v�~�f���T�Q�l�~�A�v���X�s�A
�񤣤J�U�A�e�ȹL��ˡA�껳�︹�C�������G�~�߸̡A�s�n�����R
�禳�D���h�C���v���e���G�H�A�P�y�D�X�A��ı�L���A�]�ۻP�j���C\n",]),

([ "name":GRN"�ˤs��ȹ�"NOR,
   "long": "\n
                   �m�ˤs��ȹϡn
�{�{�o�o�A��p�����_�A�����u�s�����F�����x�t�A�L�S�˴ˡA��
�����[��M�y�A�����w�歯�W�C�c�������A�i���W�ܡC���T�h�ΰf
���A�G�ѻ������A�p�w�M���K�A�O�ǥ@�d(�e)�e���뤧�~�C\n",]),

([ "name":HIY"��V�k�~��"NOR,
   "long": "\n
                   �m��V�k�~�ϡn
�����ø�e�U�A���T���h���A���]��e�C�O�U�g�m�J�X�Q�K��n��
�N�A�������ĤQ�T��A�T�W�t��֡C\n",]),

([ "name":CYN"�c�ֹ�"NOR,
   "long": "\n
                     �m�c�ֹϡn
���T�L�@�̦W�ڡA�e�k�֤Q�G�H�C�Q�H��צӧ��A���|�H���j���ơB
­�B�j��P�\�]�Ѽ־��F�ͥߤG�H���A�@�H����۩M�F��l���H��
ť�A���ܶ~�A�C���ϥ۴��_�D��ЦW���H�e�A�M�f��H����A�׵͡A
�}�y�d�T�աA�v�g�繢�A�]��e�k�Ҩt�߭�@���C\n",]),

([ "name":MAG"�J�I������"NOR,
   "long": "\n
                   �m�J�I�����ϡn
�J�I�@��A��F��צۥk�ӤW�A�@�K�����U���Aı�Ѿ�L�šA�ȥ~
���e�A�G���s�N�O�X�C�@�᱾�K�U�Y�A�p�H���^�����H�F�@��Z�F
�`�ءA�p�H�����[�S��A�u��o�������C�ܩ�ξ�����A�ε���í�A
�Φ⤧���A�צ��L�H�B�A�O���L�ڵe�j�T������~�C\n",]),

([ "name":YEL"���ө�����"NOR,
   "long": "\n
                   �m���ө����ϡn
���_�Q�|�~�]�C�����^�A�w�S�s�|�L�ϡA�����w�A���ө����פ��C
�e���ۦ���̧Y���ӡC�M�T�k�ө]�աA�X�̹D���P���U�A�E���p���A
���夣�i�C���k��l�u�ӡA�C��]��A������R�C\n",]),

([ "name":GRN"��x������"NOR,
   "long": "\n
                   �m��x�����ϡn
���T�e�����G�H�A���Ǭ����A�믫�M�`�A�A���p�͡A�x�۪ܻT�A���
���ȡF�t�@�깹�W�C����A�a�W���Y�A�@���@���A�L�@�����u�C����
Ĭ�e���ࡧ�ۦ��A��A��צp�͡A�������A���׬ۻy�����̡A�i����
�o�I�����b���L�ڡA���T�tĬ(�~��)�@�C�ǥ@�h�T�D��Ĭ�~��������
���A�H���e���̨ΡC���U������y��ø�A�y�����A�x���o�y�~�A��O
�H�ĪA���O�ǯ����ޥ��P�N�Ҫ��e�{�C\n",]),

});

void create()
{        
         mapping i = long_desc[random(sizeof(long_desc))];

         set_name(i["name"], ({ "tu juan", "tu", "juan"}));
         set("long", i["long"]);

	if (clonep())
		set_default_object(__FILE__);
	else {               
//                set("value", 1);
                set("unit", "�i");
                set("weight", 100);
                set("material", "paper");
		}
	setup();
}
