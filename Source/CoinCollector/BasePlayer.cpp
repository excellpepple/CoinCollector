// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"


// Sets default values
ABasePlayer::ABasePlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	Mesh->SetSimulatePhysics(true);
	MovementForce = 10000;

}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("MoveUp", this, &ABasePlayer::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayer::Jump);
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABasePlayer::MoveUp(float value)
{
	FVector ForceToAdd = FVector(1, 0 , 0) * MovementForce * value;
	Mesh->AddForce(ForceToAdd);
}

void ABasePlayer::MoveRight(float value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * value;
	Mesh->AddForce(ForceToAdd);
}



