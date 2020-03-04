inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�W�[", ({ "smell bad garlic", "garlic" }));
        set("long",@LONG
�o�O�@�دS�O���[�Y, ���D��@��Ʋz�Ψ쪺�[�Y�n�ӱo�W,
���O�@���ħ�, �H�s�@�v�֥~�˪��Ĭ��D, ���i�H�ͦY, ���L��
�_�Ӫ����D���h��N���o�Ӫ��o�C
LONG
);
// �{�b obj long �n�ΩM room �� long �@�˼g�k, faceoff
// �A�n�`�N�o�I.
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
// �W�[�������M�O plant �Ӫ��o...��L�ħ����ݭn���P���誺,
// �A�ݬ� mt all 
                set("value", 20);
// �D�S���ħ�, ���椣�n�L��, �X�Q�����N�⤣���F.
                set("heal_hp",5);
//              set("heal_mp",-35); <---- �o��ڵ��ѱ��F, �]�� heal ��
//                                        ����O�t��.
// �]���O�i�ͦY���ħ�, �Y���ħ��D�S���ħ�,
// �аO�o�ܤ֦��@���O����. �n���M�Y�ħ��N�n�F,
// �s�ķF����:p 
                set("heal_ap",30);
                set("attr/wound",4);  
// attr/wound �O���ħ���^�_ wound(�~��)���q, 
// ���~�٦� attr/hp  attr/mp  attr/ap.
                set("attr_one","plant"); 
// attr_one �O���������Ӫ��� or �ʪ���, �ʪ��ʴN�� plant �令 animal.
                set("attr_two","yin");  
// attr_two �O�����������ݩζ���, �ݳ��̬� yin, ���̬� yang.
// �H�W attr_one  attr_two �P attr/ �T���ħ��ݩʽзӧ� post 
// ����ӧ�.
                set("food_remaining", 1);   //��ܸ��ħ��i�H�ͦY, �ҥH�[�o��
                set("eat_msg","$N�Y�U�@�����b���o�c�䪺�W�[..!\n");
                set("eff_msg","�Aı�o�Y���I�w, ���L��O�n���^�_�F�@�I..\n");
// eat_msg �O�Y���~�ɤj�a�ݱo�쪺 msg, eff_msg �O�Y���� msg, �u���ۤv�ݱo��
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

//�o�ӳ����O�����Y�F���ħ������F��~�g��,
//�n���M�S�����, ppl �N��Y�� mp -1
//�]�i�H�@���Y..�ϥ� mp �����O -1.
//�O�o�����F�誺�����A�Τ����d�U�n�[ do_eat or do_drink ...
//�ín�o�˼g..

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("mp")<34)
        {
                return notify_fail("�A���믫�O(MP)�w�g�����F, �A�Y�N�}���o�C\n");
        }
        else
        {
                set("heal_ap",30);
                me->receive_damage("mp",35);
      
          set("heal_hp",5);
                return ::do_eat(arg);
        }
}
