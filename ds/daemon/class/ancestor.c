// �����v �@�Ψ禡
// Tmr 2007/10/11
//

#include <ansi.h>

// �]�ʵ��šG
// ���]�{�@�B���]�ɰ_�B���]����B�Ѧa�]�ơB���]�O��

int getMagic(object me, object target) 
{
        string temp_magic = "ancestor_" + me->query("id");
        return target->query_temp(temp_magic);
}

int getMagicLimit(int lv) 
{
        switch(lv) {
                case 1: return 2000;
                case 2: return 4000;
                case 3: return 8000;
                case 4: return 16000;
                case 5: return 32000;
        }
        return 0;
}

string getMagicLevelName(object me, object target)
{
        int magic = getMagic(me, target);

        if( magic >= getMagicLimit(4) )
                return "���]�O��";
        if( magic >= getMagicLimit(3) )
                return "�Ѧa�]��";
        if( magic >= getMagicLimit(2) )
                return "���]����";
        if( magic >= getMagicLimit(1) )
                return "���]�ɰ_";
       if( magic > 0 )
                return "���]�{�@";
        return "�L";
}

int getMagicLevel(object me, object target)
{
        int magic = getMagic(me, target);

        if( magic >= getMagicLimit(4) )
                return 5;
        if( magic >= getMagicLimit(3) )
                return 4;
        if( magic >= getMagicLimit(2) )
                return 3;
        if( magic >= getMagicLimit(1) )
                return 2;
       if( magic > 0 )
                return 1;
        return 0;
}


// ���]
void addMagic(object me, object target, int magic, int lv) 
{
        string temp_magic = "ancestor_" + me->query("id");
        int power = getMagic(me, target);
          if( power + magic > getMagicLimit(lv) )
                return; // �w�W�L�e�\�d��

        // �C���̦h�[3000�I
        if(magic > 3000 ) magic = 3000;

        target->add_temp(temp_magic, magic);
}

// �R�]
void deleteMagic(object me, object target)
{
        string temp_magic = "ancestor_" + me->query("id");
        target->delete_temp(temp_magic);
}


