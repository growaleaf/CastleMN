![Castle](http://projectcastle.tech/images/logo-white.png "Castle")

# Voting and Budget Proposals
If you want to vote on one of the Budget Proposals, you must own at least one masternode.

## Proposal 1:
Text
text
text

#### Proposal 1 voting hash
```
hashhashhash
```


## Proposal 2:
Text
text
text

#### Proposal 2 voting hash
```
hashhashhash
```

## Vote Calculation

The actual calculation is (YES votes - NO votes) > (Total Number of Masternodes / 10).

If there are 100 masternodes, the budget/proposal should need at least 10 YES votes without a NO vote.

## List Budget Proposals

### Using the Castle Core Wallet

Open your Castle Core wallet on your desktop, click "Tools", then select "Debug console".

Importatn `mnbudget` commands: 
```
  vote-many          - Vote on a CSTL initiative
  vote-alias         - Vote on a CSTL initiative
  vote               - Vote on a CSTL initiative/budget
  getvotes           - Show current masternode budgets
  getinfo            - Show current masternode budgets
  show               - Show all budgets
```

## Voting options
* Yes
* No
* Abstain

## Voting using Castle Core Wallet Console

To vote with all masternodes you have at once:
```
mnbudgetvote "many" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"
```
To vote with a single masternode address:
```
mnbudgetvote "alias" "wallet01" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"
```

## Voting using Castle CLI
To vote with all masternodes you have at once:
```
castle-cli mnbudgetvote "many" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"
```
To vote with a single masternode address:
```
castle-cli mnbudgetvote "alias" "wallet01" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"
```
