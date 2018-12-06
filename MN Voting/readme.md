# Voting and Budget Proposals
If you want to vote on one of the Budget Proposals, you must own at least one masternode.

## Proposal 1:
### Creation of GROW community coin, using a Castle chain snapshot
#### Voting is during blocks 43200-86401
##### Proposal 1 voting hash  
```
2e9010186eeb4f7fc6fc21b747f03f02f4b32599060a4e987d54f65393e994fb
```

Castle Core has been working with the GROW team in an advisory role for some time, through existing partnerships. GROW's goal is to use their own coin for airdrops and other promotions.  Some partnerships will consist of mutual airdrops from target communities, which will benefit GROW holders. The GROW software development will be covered by the Castle Core team, while the initial blockchain infrastructure (seed nodes, explorer, dev masternodes) will be the responsibility of the Grow team.  

From the GROW team:

"GROW coin is about helping communities organically grow, by co-marketing our brand. GROW coin is created as an crytocurrency for anyone who wants to invest in their future. GROW targets fast transactions with low fee. We want to make it much more accessible through crowdsourcing. GROW coin is created for people who believes in the principle that all people are equal and deserve equal right and opportunity. 
Together we will grow!"

<table>
  <th colspan=2>Official links:</th>

<tr><td>Website:</td><td> http://growhappy.world/</td></tr>
<tr><td>Explorer:</td><td> TBD </td></tr>
<tr><td>Discord:</td><td> https://discord.gg/SCnNCyy</td></tr>
<tr><td>Twitter:</td><td> https://twitter.com/GROW_coin</td></tr>
<tr><td>Facebook:</td><td> https://www.facebook.com/groups/growproject/</td></tr>
<tr><td>Telegram:</td><td> https://t.me/GROWcoinOfficial</td></tr>
<tr><td>Bitcointalk ANN:</td><td> TBD </td></tr>
<tr><td>Github:</td><td> TBD </td></tr>
<tr><td>CoinMarketCap</td><td>TBD </td></tr>
</table>

### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
  <tr><td>Masternode Collateral</td><td>50,000 GROW</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply</td><td>170,000,000</td></tr>
<tr><td>Premine</td><td>17,000,000</td></tr>
<tr><td>Block Time</td><td>180 seconds</td></tr>
<tr><td>Block Minting</td><td>40 confirmations</td></tr>
<tr><td>Block Transactions</td><td>5 confirmations</td></tr>
<tr><td>Block Maturity</td><td>4 hours</td></tr>
<tr><td>Minimum Stake Age</td><td>6 hours</td></tr>
</table>



## Vote Calculation

The actual calculation is (YES votes - NO votes) > (Total Number of Masternodes / 10).

If there are 100 masternodes, the budget/proposal should need at least 10 YES votes without a NO vote.

## List Budget Proposals

### Using the Castle Core Wallet

Open your Castle Core wallet on your desktop, click "Tools", then select "Debug console".

Important `mnbudget` commands: 
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
mnbudgetvote "many" "enter proposal hash" "yes"
```
To vote with a single masternode address:
```
mnbudgetvote "alias" "wallet01" "enter proposal hash" "yes"
```

## Voting using Castle CLI
To vote with all masternodes you have at once:
```
castle-cli mnbudgetvote "many" "enter proposal hash" "yes"
```
To vote with a single masternode address:
```
castle-cli mnbudgetvote "alias" "wallet01" "enter proposal hash" "yes"
```
