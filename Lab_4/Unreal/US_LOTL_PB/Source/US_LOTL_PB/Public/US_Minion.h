// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "US_Minion.generated.h"

UCLASS()
class US_LOTL_PB_API AUS_Minion : public ACharacter
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minion Perception", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPawnSensingComponent> PawnSense;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minion Perception", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> Collision;
	UPROPERTY()
	FVector PatrolLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI", meta = (AllowPrivateAccess = "true"))
	float AlertRadius = 6000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float Health = 5.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AUS_BasePickup> SpawnedPickup;

public:
	// Sets default values for this character's properties
	AUS_Minion();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float PatrolSpeed = 150.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float ChaseSpeed = 350.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float PatrolRadius = 50000.0f;
	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void SetNextPatrolLocation();
	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void Chase(APawn* Pawn);
	virtual void PostInitializeComponents() override;
	FORCEINLINE UPawnSensingComponent* GetPawnSense() const { return PawnSense; }
	FORCEINLINE USphereComponent* GetCollision() const { return Collision; }

	UFUNCTION()
	void OnPawnDetected(APawn* Pawn);
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	UFUNCTION()
	void OnDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void GoToLocation(const FVector& Location);
};
