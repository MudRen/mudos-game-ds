// attribute.c

// update 2009/05/04 - Tmr
//        �~��(BAR)�G�C�I�W�[ �����O 4%
//        �ͪ�(BIO)�G�C�I�W�[ ���z���m 4%
//        �]�k(WIT)�G�C�I�W�[ �����O 4%
//        ���F(SOU)�G�C�I�W�[ �]�k���m 4%
//        ���(TEC)�G�C�I�W�[ ���z���m 2%�A���z���m 2%

//        �~��(BAR)�G�C3�I�W�[ �����ˮ` 1%
//        �]�k(WIT)�G�C3�I�W�[ �����ˮ` 1% 
//        �ͪ�(BIO)�G�C�I�W�[  �����ˮ` 1% 
//        ���F(SOU)�G�C3�I�W�[ �����ˮ` 2% ������� 1%
//        ���(TEC)�G�C3�I�W�[ �����ˮ` 1% ������� 2%

#include <dbase.h>

// �򥻼����ˮ` 
#define DEFAULT_HIT_POWER 10

int query_str();
int query_con();
int query_int();
int query_dex();

int query_bar();
int query_bio();
int query_wit();
int query_sou();
int query_tec();

int query_total_gift()  //�Ǧ^�ݩ��`�M (�Ω���ݩ��ˬd)
{
        return (int)query("str")
                +(int)query("con")
                +(int)query("dex")
                +(int)query("int");
}


int query_damage()      //�Ǧ^���z�ʧ����O
{
        int value = (int)query_temp("apply/damage")
                + query_temp("spell/damage")
                + query("addition_damage")      //for NPC
                + (int)(query_str())
                + 2;                            // �[�jPPL&NPC�������O, �H�Y�u�԰��ɶ�
                
        return (value + value*query_bar()*4/100 + value*query_wit()*4/100);
}

int query_armor()       //�Ǧ^���z�ʨ��m�O
{
        int value = (int)query_temp("apply/armor")
                + query_temp("spell/armor")
                + query("addition_armor");      //for NPC
                
                return (value + value * query_bio()*4/100 + value * query_tec()*2/100);
}

int query_shield()      //�Ǧ^�D���z�ʨ��m�O(�]�k��ܤO)
{
        int value = (int)query_temp("apply/shield")
                + query_temp("spell/shield")
                + query("addition_shield")      //for NPC
                + query_int();
        
        return (value + value*query_sou()*4/100 + value*query_tec()*2/100);
}

int query_str()         //�Ǧ^STR(�O�q)��(�]�t���[�ĪG)
{
        int i,j,k,l=0;
        string *eff_limbs;
 
        i = query("str")
                + query_temp("apply/str")
                + query_temp("spell/str")
                + query("addition/str");
        eff_limbs=query("limbs_effect/str");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_int()         //�Ǧ^INT(���z)��(�]�t���[�ĪG)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("int")
                + query_temp("apply/int")
                + query_temp("spell/int")
                + query("addition/int");
        eff_limbs=query("limbs_effect/int");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_dex()         //�Ǧ^DEX(�ӱ�)��(�]�t���[�ĪG)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("dex")
                + query_temp("apply/dex")
                + query_temp("spell/dex")
                + query("addition/dex");
        eff_limbs=query("limbs_effect/dex");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;       
}

int query_con()         //�Ǧ^CON(���)��(�]�t���[�ĪG)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("con")
                + query_temp("apply/con")
                + query_temp("spell/con")
                + query("addition/con");
        eff_limbs=query("limbs_effect/con");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_bio()         // �^�� Biological(�ͪ�) ��
{
	return query("Merits/bio")+query_temp("apply/bio")
        + query_temp("spell/bio")+query("addition/bio");
}

int query_bar()         // �^�� Barbarity(�~��) ��
{
	return query("Merits/bar")+query_temp("apply/bar")
        + query_temp("spell/bar")+query("addition/bar");
}


int query_wit()         // �^�� Witchcraft(�]�k) ��
{
		return query("Merits/wit")+query_temp("apply/wit")
        + query_temp("spell/wit")+query("addition/wit");
}

int query_sou()         // �^�� Soul(���F) ��
{
		return query("Merits/sou")+query_temp("apply/sou")
        + query_temp("spell/sou")+query("addition/sou");
}


int query_tec()         // �^�� Technology(���) ��
{
       return query("Merits/tec")+query_temp("apply/tec")
        + query_temp("spell/tec")+query("addition/tec");
}

int query_total_merits()        // �^�ǩҦ����誺�`�M
{
       return query_bio()+query_bar()+query_wit()
        +query_sou()+query_tec();
}

int query_Merits(string Merits_type)
{
        switch(Merits_type)
        {
                case "bio": return query_bio(); break;
                case "bar": return query_bar(); break;
                case "wit": return query_wit(); break;
                case "sou": return query_sou(); break;
                case "tec": return query_tec(); break;
                default : return 0;
        }
}

// �����v
int query_hit() {
	int tt;
	tt = query_str() + query_con() + query_int() + query_dex();
	return tt/100 + 
		query_temp("apply/hit_ratio") + 
			this_object()->query_skill("constant-virtue")/10;
}

// �����ˮ`
int query_hitpower() {
	return DEFAULT_HIT_POWER + query_temp("apply/hit_power")
	+ query_bio()*3 
	+ query_sou()/3*6
	+ query_bar() + 
	query_wit() + 
	query_tec() +
          this_object()->query_skill("constant-virtue")/2;
}

// �������
int query_hit_against() {
	return query_temp("apply/hit_against") 
		+ query_sou()/3 
		+ query_tec()/3*2+
		this_object()->query_skill("constant-virtue")/10;
}

// �R���v
int query_accuracy() {
	return 0;
}
