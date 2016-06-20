#pragma once
#include "BackGround.h"
#include "Hero.h"
#include "PersonState.h"
#include "Contrl.h"
#include "Talking.h"
#include "HeroS.h"
class GameMessage
{
public:
	GameMessage();
	~GameMessage();
	static int is_talking;
	static void TalkMessage();
	static int talking_step;
	static int _OK;
	static int pre_step;
	static int next_step;
	static int is_stop;
	static int Hero_score;
	static int Hero2_score;
	static int Count_Num;					//��Ϸ�ӽǻ��������
	static int step;						//��Ϸ����
	static int boss_num;					//boss������
	static int Hero_Kind;					//Ӣ������
	static int Hero2_Kind;
	static void RandomEnemy(int lv);		//���е��˵�����
	static int Hero_Life;					//Ӣ��������
	static int Hero2_Life;					//Ӣ��������
	static Hero* hero;						//ӵ��һ��Ӣ��
	static Hero* hero2;					   //ӵ��2��Ӣ��
	static HeroS* L_Hero;					//Ӣ�۵�С��
	static HeroS* L_Hero2;					//Ӣ�۵�С��
	static PersonState* state1;				//��һ��Ӣ��״̬����
	static PersonState* state2;
	static CRect rect;						//����
	static CObList Enemy1_List;				//�л�һ�Ż�Ⱥ
	static CObList Enemy2_List;				//�л����Ż�Ⱥ
	static CObList Enemy3_List;				//�л����Ż�Ⱥ
	static CObList Enemy4_List;				//�л��ĺŻ�Ⱥ
	static CObList Enemy5_List;				//�л���Ż�Ⱥ
	static CObList Boss_List;				//BOSS����
	static CObList Explo_List;				//��ը��Ч
	static CObList Word_List;				//����
	static CObList Enemy_Bullet_List;		//�����ӵ�������
	static CObList Things_List;				//��Ʒ����		   
	static void ShowBackground(CDC* cDC);	//�������ƺ���
	static BackGround* background;			//һ������ͼ
	static BackGround* boombackground;		//���б���ͼ
	static BackGround* boombackground2;		//���б���ͼ
	static Talking* talkground;		//���б���ͼ
	static void GetKeyAttack();				//���Ӣ�۹�����Ϣ
	static void ShowHero(CDC* cDC);			//Ӣ�ۻ��ƺ���
	static void ShowHeroLife(CDC* cDC);		//��ʾӢ������
	static void ShowEnemy1(CDC* cDC);		//�л�һ�ŵĻ���
	static void ShowEnemy2(CDC* cDC);		//�л����ŵĻ���
	static void ShowEnemy3(CDC* cDC);		//�л����ŵĻ���
	static void ShowEnemy4(CDC* cDC);		//�л��ĺŵĻ���
	static void ShowEnemy5(CDC* cDC);		//�л���ŵĻ���
	static void ShowEnemyBoss(CDC* cDC);	//BOss�Ļ���
	static void ShowExplo(CDC* cDC);		//���յĻ���
	static void ShowWord(CDC* cDC);			//���ֵĻ���
	static void ShowEnemyBullet(CDC* cDC);	//�л��ӵ�����
	static void ShowState(CDC* cDC);		//״̬���ڵĻ���
	static void ShowThings(CDC* cDC);		//��Ʒ����
	static void EnemyAttack1();				//���й������ж�
	static void EnemyAttack2();				//���й������ж�
	static void EnemyAttack3();				//���й������ж�
	static void EnemyAttack4();
	static void EnemyAttack5();
	static void BossAttack();				//BOOS������
	static void HeroAttack();				//Ӣ�۱������ж�
	static void GameInit();					//��Ϸ��ʼ��
	static void Big_Boom();					//�����ը
	static void GameManage();				//��Ϸ���ȵĹ���
	static void GameStop();					//��Ϸ�ٶȵ�ֹͣ����
	static void GameStart();				//��Ϸ�ٶȻ���
	static void GameToStop();				//��ͣ��Ϸ
	static void GameCombine();				//���弼��
	static void PlaneHit();					//ս����ײ����
	static void ThingHit();					//Ӣ�۳���Ʒ����
};

